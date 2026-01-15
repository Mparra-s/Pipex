/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:44:18 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/11 16:53:01 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	int				i;

	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (cdest > csrc && cdest < csrc + size)
	{
		while (size--)
			cdest[size] = csrc[size];
	}
	else
	{
		while (size--)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (cdest);
}

/*int	main(void)
{
	char    src[] = "Mundo arrasador";
	char    dest[] = "Acabemos";
	size_t	size;

	size = 4;
	ft_memmove(dest, src, size);
	return (0);
}*/
