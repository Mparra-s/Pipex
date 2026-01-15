/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:43:37 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 09:52:24 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int print)
{
	if (print > 31 && print < 127)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	print;

	print = 'a';
	ft_isprint (print);
	return (0);
}*/
