/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:57:02 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/25 15:13:50 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(unsigned int num, int *count, const char *base)
{
	unsigned int	n;

	if (num > 15)
		ft_recursive(num / 16, count, base);
	n = (num % 16);
	write(1, &base[n], 1);
	(*count)++;
}

int	ft_printf_putnbr_hex(va_list vargs, int *count, char type)
{
	unsigned int	num;
	const char		*base;

	num = va_arg (vargs, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return (*count);
	}
	if (type != 'x' && type != 'X')
		return (*count);
	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_recursive (num, count, base);
	return (*count);
}
/*int main (void)
{
    unsigned int    number = 736462782;
    int     count;
    char    type = 'X';
    
    count = 0;
    ft_printf_putnbr_hex(number, count, type);
    return (0);    
}*/
