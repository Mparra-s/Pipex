/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:44:46 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/10 12:44:48 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	length_dest;
	unsigned int	length_src;
	unsigned int	i;

	i = 0;
	length_dest = 0;
	length_src = 0;
	while (src[length_src])
		length_src++;
	while (dest[length_dest])
		length_dest++;
	if (length_dest >= size)
		return (length_src + size);
	while (src[i] != '\0' && (length_dest + i < size - 1))
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = '\0';
	return (length_dest + length_src);
}

/*int	main (void)
{
	char	destiny[] = "mundo";
	char	string[] = "hola mundo";
	unsigned int	length = 10;

	ft_strlcat(destiny, string, length);
	return (0);
}*/
