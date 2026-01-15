/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:16 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/10 11:09:55 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(long num, int *count)
{
	char	n;

	if (num > 9)
		ft_recursive(num / 10, count);
	n = (num % 10) + '0';
	(*count)++;
	write(1, &n, 1);
}

int	ft_printf_putnbr(va_list vargs, int *count)
{
	long	num;

	num = (long) va_arg (vargs, int);
	if (num < 0)
	{
		write (1, "-", 1);
		num = -num;
		(*count)++;
	}
	ft_recursive (num, count);
	return (*count);
}
