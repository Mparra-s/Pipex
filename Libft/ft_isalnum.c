/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:42:52 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/10 12:42:58 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	unsigned char	c;

	c = (unsigned char)alnum;
	if ((c > 47 && c < 58) || (c > 64 && c < 91)
		|| (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	alnum;

	alnum = 'A';
	ft_isalnum (alnum);
	return (0);
}*/
