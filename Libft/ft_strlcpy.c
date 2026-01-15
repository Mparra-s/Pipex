/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:44:54 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/10 12:44:56 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (src[length] != 0)
		length++;
	if (size == 0)
		return (length);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

/*int	main(void)
{
	char	sarc[] = "Hola mundo";
	char	destino[] = "perro viejo";
	unsigned int		length = 4;

	ft_strlcpy(destino, sarc, length);
	printf("frase %s \n", destino);
	return (0);
}*/
