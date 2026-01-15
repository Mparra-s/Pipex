/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:45:21 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 11:22:50 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*s1;
	const char	*s2;
	int			a;
	size_t		i;

	s1 = str;
	s2 = to_find;
	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] != '\0' && i <= len)
	{
		a = 0;
		while (s1[i + a] == s2 [a] && (i + a) < len)
		{
			if (s2[a + 1] == '\0')
				return ((char *)&s1[i]);
			a++;
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char	string[] = "Hola mundo que tal, saluda al mundo";
	const char	find[] = "tal";
	const char *hola;
	int	len = 250;

	hola = ft_strnstr(string, find, len);
	printf("%s", hola);
	return (0);
}*/
