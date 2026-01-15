/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 08:58:01 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/10 11:10:02 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putchar(va_list vargs, int *count)
{
	char	c;

	c = (char) va_arg (vargs, int);
	write (1, &c, 1);
	(*count)++;
	return (*count);
}
