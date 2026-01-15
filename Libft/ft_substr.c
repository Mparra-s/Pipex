/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:55:55 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/25 14:01:26 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t length)
{
	size_t	length_dest;
	size_t	length_str;
	size_t	i;
	char	*dest;

	i = 0;
	if (str == NULL)
		return (NULL);
	length_str = ft_strlen(str);
	if (start >= length_str)
		return (NULL);
	if (length_str - start < length)
		length_dest = length_str - start;
	else
		length_dest = length;
	dest = (char *)malloc(length_dest + 1);
	if (dest == NULL)
		return (NULL);
	while (i < length_dest)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	sentence[] = "Hola mundo";
	unsigned int	letter = 'm';
	size_t	length = 5;

	printf("%s\n", ft_substr(sentence, letter, length));
	return (0);
}*/
