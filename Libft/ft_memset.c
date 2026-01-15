/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:44:28 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 11:20:42 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	unsigned char	car;
	char			*sentence;
	size_t			i;

	sentence = (char *) str;
	car = (unsigned char) c;
	i = 0;
	while (i < size)
	{
		sentence[i] = car;
		i++;
	}
	return (sentence);
}

/*int	main(void)
{
	char    str[] = "";
	char    c;
	int size;

	c = 'S';
	size = 2;
	ft_memset(str, c, size);
	return (0);
}*/
