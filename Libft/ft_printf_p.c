/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:49:28 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/10 11:09:59 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(unsigned long str, int *count, const char *base)
{
	unsigned int	letter;

	if (str > 15)
		ft_recursive (str / 16, count, base);
	letter = str % 16;
	write(1, &base[letter], 1);
	(*count)++;
}

int	ft_printf_p(va_list vargs, int *count)
{
	unsigned long	str;
	const char		*base;

	base = "0123456789abcdef";
	str = va_arg(vargs, unsigned long);
	if (str == 0)
	{
		write (1, "(nil)", 5);
		(*count) += 5;
		return (*count);
	}
	write (1, "0x", 2);
	(*count) += 2;
	ft_recursive(str, count, base);
	return (*count);
}

/*int main(void)
{
    char   *string;
    int     count;
    
    count = 0;
    string = "abcde"; 
    ft_printf_p(NULL, &count);
    printf("%p", NULL);
    return (0);
}*/
