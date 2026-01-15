/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:43:20 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 11:21:29 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int ascii)
{
	if (ascii >= 0 && ascii <= 127)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	ascii;

	ascii = ' ';
	ft_isascii (ascii);
	return (0);
}*/
