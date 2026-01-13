#include "pipex.h"

void	execute_command(char *cmd, char **envp)
{
	char	**array;
	char	*path;

	get_arguments(cmd, &array, &path, envp);
	if (!path || !array || !array[0])
	{
		perror ("Invalid command");
		free (path);
		free_arguments (array);
		exit(EXIT_FAILURE);
	}
	execve (path, array, envp);
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
	if (pid == 0)
	{
		input_fd = open_file_in(file, pipex);
		dup_ver (dup2(input_fd, STDIN_FILENO), "dup2 input_fd");
		dup_ver (dup2(pipex->pipe_fd[1], STDOUT_FILENO), "dup2 pipe_fd");
		close (input_fd);
		close_pipes (pipex);
		execute_command (cmd, pipex->envp);
		exit (EXIT_FAILURE);
	}
	return (pid);
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
		output_fd = open_file_out(file, pipex);								
		dup_ver (dup2(pipex->pipe_fd[0], STDIN_FILENO), "dup2 pipe_fd");	
		dup_ver (dup2(output_fd, STDOUT_FILENO), "dup2 output_fd");
		close (output_fd);
		close_pipes (pipex);
		execute_command (cmd, pipex->envp);
		exit (EXIT_FAILURE);
	}
	return (pid);
}


int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;
	pid_t	pid[2];
	int		status;

	if (argc != 5)
	{
		write(2, "Use: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 42);
		return (EXIT_FAILURE);
	}
	pipex.envp = envp;
	if (create_pipe(pipex.pipe_fd) != 0)
		return (EXIT_FAILURE);
	pid[0] = first_child(argv[2], argv[1], &pipex);
	pid[1] = second_child(argv[3], argv[4], &pipex);
	close(pipex.pipe_fd[0]);											
	close(pipex.pipe_fd[1]);
	waitpid(pid[0], NULL, 0);									
	waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
