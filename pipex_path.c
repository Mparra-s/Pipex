#include "pipex.h"

char	*validation_path(char *path, char **array)
{
	char	*temp;
	char	*full_path;

	if (!path || !array || !array[0])
		return (NULL);
	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, array[0]);
	free (temp);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	free (full_path);
	return (NULL);
}

char	*search_cmd(char **array, char **path)
{
	char	*result;				
	int		i;

	i = 0;
	while (path[i])									
	{												
		result = validation_path(path[i], array);   
		if (result)
			return (result);
		i++;
	}
	return (NULL);
}

char	**get_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)  
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*get_path(char **array, char **envp)
{
	char	**path;
	char	*full_path;

	if (ft_strchr(array[0], '/'))
	{
		if (access(array[0], X_OK) == 0)
			return (ft_strdup(array[0]));
		else
			return (NULL);
	}
	path = get_envp(envp);						
		return (NULL);
	full_path = search_cmd(array, path);
	free_arguments(path);
	return (full_path);
}

void	get_arguments(char *cmd, char ***array, char **path, char **envp)
{
	*array = ft_split(cmd, ' ');
	if (!*array || !(*array)[0])
	{
		free_arguments(*array);
		not_found(cmd);
		exit (127);
	}
	*path = get_path(*array, envp);
	if (!*path)
	{
		if (ft_strchr(cmd, '/')) 
		{
			if (access(cmd, F_OK) != 0) 
				not_found(cmd);
			else if (access(cmd, X_OK) != 0)
				per_denied(cmd);
			else
			{
				perror("pipex");
				exit(126);
			}
		}
		else
			not_found(cmd);
	}
}
