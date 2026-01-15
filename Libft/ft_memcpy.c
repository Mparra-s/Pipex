/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:44:10 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/12 16:52:39 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned int		i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	i = 0;
	if (!dest || !src)
		return (0);
	while (i < (unsigned int)size)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

/*int	main(void)
{
	int		size;
	char	*dest = NULL;
	char	src[] = "Hola";

	size = 2;
	ft_memcpy(dest, src, size);
	return (0);
}*/
