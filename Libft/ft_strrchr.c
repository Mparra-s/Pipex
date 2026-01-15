/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:45:30 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/25 08:45:21 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	letter;
	const char		*cstr;
	int				length;

	cstr = str;
	letter = (unsigned char) c;
	length = 0;
	while (cstr[length] != 0)
		length++;
	while (length >= 0)
	{
		if (cstr[length] == letter)
			return ((char *)cstr + length);
		length--;
	}
	return (0);
}

/*int	main(void)
{
	const char	sentence[] = "Hola mundo, adios mundo";
	int	c = 's';

	printf("%s", ft_strrchr(sentence, c));
	return (0);
}*/
