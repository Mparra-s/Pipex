/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:40:47 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/12 16:51:02 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*dest;

	i = 0;
	j = 0;
	length = ft_strlen(str);
	if ((str == NULL) || (set == NULL))
		return (NULL);
	while (str[i] != '\0' && ft_strchr(set, str[i]) != NULL)
		i++;
	while (length > i && ft_strchr(set, str[length -1]) != NULL)
		length--;
	dest = malloc (length - i + 1);
	if (dest == NULL)
		return (NULL);
	while (i < length)
		dest[j++] = str[i++];
	dest[j] = '\0';
	return (dest);
}

/*int main(void)
{
    const char string[] = "Hola mundo que tal, hola";
    const char find[] = "lHao";

    printf("%s", ft_strtrim(string, find));
    return(0);
}*/
