#include "pipex.h"

int	create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
	{
		perror ("pipe");
		return (EXIT_FAILURE);
	}
	return (0);
}

void	close_pipes(t_pipex *pipex)
{
	close (pipex->pipe_fd[0]);
	close (pipex->pipe_fd[1]);
}

void	free_arguments(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i])
	{
		free (path[i]);
		i++;
	}
	free (path);
}

int	open_file_out(char *file, t_pipex *pipex)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);i
	if (fd < 0)
	{
		perror (file);
		close_pipes (pipex);
		exit (EXIT_FAILURE);
	}
	return (fd);
}

int	open_file_in(char *file, t_pipex *pipex)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_fd(file, pipex);
	return (fd);
}
