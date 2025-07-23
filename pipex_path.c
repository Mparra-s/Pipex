/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:22:59 by mparra-s          #+#    #+#             */
/*   Updated: 2025/07/22 19:04:14 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Construye una ruta completa combinando un directorio (path) y el nombre del comando (array[0]), y verifica si ese archivo existe y es ejecutable.*/
char	*validation_path(char *path, char **array)
{
	char	*temp;
	char	*full_path;

	if (!path || !array || !array[0])
		return (NULL);
	temp = ft_strjoin(path, "/");			//Crea una cadena temporal concatenando el directorio con / (Por ejemplo, si path = "/bin", temp será "/bin/").
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, array[0]);	//Une la cadena temporal con el nombre del comando (Por ejemplo: "/bin/" + "ls" → "/bin/ls".)
	free (temp);
	if (!full_path)
		return (NULL);
	if (access(full_path, X_OK) == 0)		//Usamos access para comprobar que el archivo existe y tiene permiso de ejecución.
		return (full_path);					//Si se cumple devolvemos la ruta completa.
	free (full_path);
	return (NULL);
}
/* En array pasamos el argumento del comando, donde array[0] es el nombre del ejecutable ("ls")
En path pasamos el arreglo de directorios donde buscar el ejecutable (ej. "/bin", "/usr/bin")*/
char	*search_cmd(char **array, char **path)
{
	char	*result;				
	int		i;

	i = 0;
	while (path[i])									//En cada directorio llamamos a una función que construye la ruta completa (ej. "/bin/ls")
	{												//Comprueba si el ejecutable existe y tiene permisos de ejecución.
		result = validation_path(path[i], array);   //Devuleve la ruta completa si es válido.
		if (result)
			return (result);						//Si validation path devuelve una ruta válida retornamos esa ruta y terminamos.
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
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)  //Buscamos en las variables de entorno la variable PATH.
			return (ft_split(envp[i] + 5, ':'));   //Extraemos su valor (los directorios separados por :) y dividimos el valor en un arreglo de strings.
		i++;
	}
	return (NULL);
}

char	*get_path(char **array, char **envp)
{
	char	**path;
	char	*full_path;

	if (ft_strchr(array[0], '/'))				//Si el comando ya contiene una / (ruta relativa o absoluta)
	{
		if (access(array[0], X_OK) == 0)		//Comprueba si se puede ejecutar.
			return (ft_strdup(array[0]));		//Si puede devuelve una copia de la ruta.
		else
			return (NULL);
	}
	path = get_envp(envp);						//Si el comando no tiene / entonces tenemos que obtener un arreglo de strings con los directorios del path.
	if (!path)
		return (NULL);
	full_path = search_cmd(array, path);		//llama a una función para buscar el ejecutable en cada directorio de path. 
	free_arguments(path);
	return (full_path);
}

/* Divide el comando cmd en un arreglo de argumentos (como argv).
Busca la ruta absoluta del ejecutable.*/

void	get_arguments(char *cmd, char ***array, char **path, char **envp)
{
	*array = ft_split(cmd, ' ');     	//Separamos los comandos en el caso que sea complejo.
	if (!*array || !(*array)[0])
	{
		free_arguments(*array);
		not_found(cmd);
		exit (127);
	}
	*path = get_path(*array, envp);		//Llama a get_path para buscar la ruta absoluta del ejecutable. Busca en las rutas listadas en la variable PATH dentro de envp.
	if (!*path)
	{
		if (ft_strchr(cmd, '/'))       			//Si el comando contiene / (es decir, es una ruta relativa o absoluta, como ./script.sh o /bin/ls):
		{
			if (access(cmd, F_OK) != 0) 		//Comprueba si el archivo existe.
				not_found(cmd);
			else if (access(cmd, X_OK) != 0)	//Comprueba si el archivo tiene permisos.
				per_denied(cmd);
			else								//Si falla por otros motivos.
			{
				perror("pipex");
				exit(126);
			}
		}
		else									//Si el comando no tiene / y no se encontró en la ruta PATH.
			not_found(cmd);
	}
}
