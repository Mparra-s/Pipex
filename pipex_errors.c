/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:33:04 by mparra-s          #+#    #+#             */
/*   Updated: 2025/07/21 18:49:02 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	not_found(char *cmd)
{
	write(2, "pipex: command not found: ", 26);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(127);
}

int	per_denied(char *cmd)
{
	write(2, "pipex: permission denied: ", 26);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(126);
}

void	error_fd(char *file, t_pipex *pipex)
{
	if (errno == ENOENT)
	{
		write(2, "pipex: no such file or directory: ", 34);
		write(2, file, ft_strlen(file));
		write(2, "\n", 1);
		close_pipes(pipex);
		exit(1);
	}
	else if (errno == EACCES)
	{
		close_pipes(pipex);
		per_denied(file);
		exit(126);
	}
	else
	{
		perror(file);
		close_pipes(pipex);
		exit(EXIT_FAILURE);
	}
}
