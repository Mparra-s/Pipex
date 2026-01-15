/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:23:09 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/12 16:54:48 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_validate_format(char variable, va_list vargs, int *count)
{
	if (variable == 'c')
		ft_printf_putchar (vargs, count);
	else if (variable == 's')
		ft_printf_putstr (vargs, count);
	else if (variable == 'd' || variable == 'i')
		ft_printf_putnbr (vargs, count);
	else if (variable == 'u')
		ft_printf_putnbru (vargs, count);
	else if (variable == 'p')
		ft_printf_p (vargs, count);
	else if (variable == 'x' || variable == 'X')
		ft_printf_putnbr_hex (vargs, count, variable);
	else if (variable == '%')
	{
		ft_putc_fd2 ('%', 1);
		(*count)++;
	}
	else
		return (0);
	return (1);
}

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		i;
	int		count;

	va_start (vargs, str);
	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1]
			&& ft_validate_format (str[++i], vargs, &count))
			i++;
		else
		{
			ft_putc_fd2 (str[i], 1);
			count++;
			i++;
		}
	}
	va_end (vargs);
	return (count);
}

/*int main (void)
{ 
    ft_printf("%c", 'a');
    printf("%c", 'a');
    return 0;
}*/
