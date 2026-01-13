#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "Libft/libft.h"

typedef struct s_pipex
{
	char	**envp;
	int		pipe_fd[2];
}	t_pipex;

char	**get_envp(char **envp);
char	*validation_path(char *path, char **array);
char	*search_cmd(char **array, char **path);
char	*get_path(char **array, char **envp);
void	close_pipes(t_pipex *pipex);
void	free_arguments(char **path);
void	execute_command(char *cmd, char **envp);
void	get_arguments(char *cmd, char ***array, char **path, char **envp);
void	dup_ver(int dup_val, char *message);
void	error_fd(char *file, t_pipex *pipex);
int		first_child(char *cmd, char *file, t_pipex *pipex);
int		second_child(char *cmd, char *file, t_pipex *pipex);
int		create_pipe(int pipe_fd[2]);
int		open_file_out(char *file, t_pipex *pipex);
int		open_file_in(char *file, t_pipex *pipex);
int		not_found(char *cmd);
int		per_denied(char *cmd);
#endif
