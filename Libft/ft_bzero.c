/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:42:28 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 11:54:02 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t size)
{
	unsigned char	*csrc;
	size_t			i;

	csrc = (unsigned char *) src;
	i = 0;
	while (i < size)
	{
		csrc[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	unsigned char	src[] = "Hola mundo";
	size_t	i;

	i = 4;
	ft_bzero(src, i);
	return (0);
}*/
