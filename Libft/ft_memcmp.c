/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:44:04 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 12:04:26 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	unsigned const char	*csrc1;
	unsigned const char	*csrc2;
	size_t				i;

	csrc1 = (unsigned const char *) src1;
	csrc2 = (unsigned const char *) src2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (csrc1[i] != csrc2[i])
			return (csrc1[i] - csrc2[i]);
		i++;
	}
	return (0);
}

/*int	main (void)
{
	unsigned char	s1[] = "Hola mundo";
	unsigned char	s2[] = "Hola perro";
	size_t		n = 0;

	memcmp(s1, s2, n);
	return (0);
}*/
