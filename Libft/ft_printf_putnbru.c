/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbru.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:48:12 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/10 11:10:10 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(unsigned int num, int *count)
{
	unsigned char	n;

	if (num > 9)
		ft_recursive(num / 10, count);
	n = (num % 10) + '0';
	(*count)++;
	write (1, &n, 1);
}

int	ft_printf_putnbru(va_list vargs, int *count)
{
	unsigned int	num;

	num = va_arg (vargs, unsigned int);
	ft_recursive (num, count);
	return (*count);
}
