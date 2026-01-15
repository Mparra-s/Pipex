/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:11:02 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 14:26:06 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	length1;
	size_t	length2;
	size_t	i;
	char	*dest;

	length1 = ft_strlen(str1);
	length2 = ft_strlen(str2);
	dest = malloc(length1 + length2 + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		dest[i] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		dest[i + length1] = str2[i];
		i++;
	}
	dest[i + length1] = '\0';
	return (dest);
}

/*int main (void)
{
    char    string1[] = "Hola mundo";
    char    string2[] = "Adios mundo";

    ft_strjoin(string1, string2);
    return (0);
}*/
