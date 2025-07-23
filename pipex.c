/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:09:20 by mparra-s          #+#    #+#             */
/*   Updated: 2025/07/22 19:27:50 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*Esta función se encarga de ejecutar un comando en el proceso actual usando execve, que reemplaza el proceso por el ejecutable especificado.
Lo separa en sus distintos componentes "ls -l" || array = {"ls", "-l", NULL}
Busca la ruta completa del ejecutable (/bin/ls)
Llama a execve ("/bin/ls", array, envp)
 */
void	execute_command(char *cmd, char **envp)
{
	char	**array;								// Contiene los argumentos del comando (cmd) ya separados
	char	*path;									// Ruta completa del ejecutable.

	get_arguments(cmd, &array, &path, envp);
	if (!path || !array || !array[0])
	{
		perror ("Invalid command");
		free (path);
		free_arguments (array);
		exit(EXIT_FAILURE);
	}
	execve (path, array, envp);						// execve reemplaza el proceso actual con el nuevo programa (path), pasándole los argumentos y variables de entorno.
	perror ("execve");
	free (path);
	free_arguments (array);
	exit (EXIT_FAILURE);
}

void	dup_ver(int dup_val, char *message)
{
	if (dup_val < 0)
	{
		perror (message);
		exit (EXIT_FAILURE);
	}
}

int	first_child(char *cmd, char *file, t_pipex *pipex)
{
	pid_t	pid;
	int		input_fd;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0)							//Sólo se ejecuta en el hijo (por eso el PID es 0)
	{
		input_fd = open_file_in(file, pipex);								//Abrimos el archivo de entrada y devolvemos el descriptor de archivo.
		dup_ver (dup2(input_fd, STDIN_FILENO), "dup2 input_fd");			//Redirigimos el STDIN para que lea desde el archivo.
		dup_ver (dup2(pipex->pipe_fd[1], STDOUT_FILENO), "dup2 pipe_fd");	//Redirigimos el STDOUT para que escriba en el extremo del pipe.
		close (input_fd);
		close_pipes (pipex);
		execute_command (cmd, pipex->envp);
		exit (EXIT_FAILURE);
	}
	return (pid);							//Retornamos el PID del hijo.
}

int	second_child(char *cmd, char *file, t_pipex *pipex)
{
	pid_t	pid;
	int		output_fd;

	pid = fork();
	if (pid < 0)
	{
		perror ("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		output_fd = open_file_out(file, pipex);								//Abrimos el archivo de salida.
		dup_ver (dup2(pipex->pipe_fd[0], STDIN_FILENO), "dup2 pipe_fd");	//Redirigimos el STDIN para que lea desde el extremo del pipe.
		dup_ver (dup2(output_fd, STDOUT_FILENO), "dup2 output_fd");			//Redirigimos el STDOUT (salida estándar) para que escriba en el archivo.
		close (output_fd);
		close_pipes (pipex);
		execute_command (cmd, pipex->envp);
		exit (EXIT_FAILURE);
	}
	return (pid);							//Retornamos el PID del hijo.
}


/*Las pipes permiten que la salida de un comando se convierta en la entrada de otro, sin necesidad de archivos intermedios.*/
int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;
	pid_t	pid[2];
	int		status;															//Captura el código de salida del segundo hijo.

	if (argc != 5)
	{
		write(2, "Use: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 42);
		return (EXIT_FAILURE);
	}
	pipex.envp = envp;														//Guardamos el entorno.
	if (create_pipe(pipex.pipe_fd) != 0)
		return (EXIT_FAILURE);
	pid[0] = first_child(argv[2], argv[1], &pipex);
	pid[1] = second_child(argv[3], argv[4], &pipex);
	close(pipex.pipe_fd[0]);												//Cerramos los pipes en el padre ya que este no tiene ni que leer ni que escribir.
	close(pipex.pipe_fd[1]);
	waitpid(pid[0], NULL, 0);												//Esperamos a que termine el primer hijo ignorando su código de salida.
	waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
