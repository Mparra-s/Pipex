/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:43:50 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 10:31:34 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *scr, int c, size_t len)
{
	unsigned char	letter;
	unsigned char	*cscr;
	size_t			i;

	letter = (unsigned char) c;
	cscr = (unsigned char *) scr;
	i = 0;
	while (i < len)
	{
		if (cscr[i] == letter)
		{
			return ((void *)&cscr[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	sentence[] = "Hola mundo";
	int	c = 'a';
	size_t	len = 8;

	memchr(sentence, c, len);
	return (0);
}*/
