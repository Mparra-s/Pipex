/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:01:37 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/10 11:10:12 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putstr(va_list vargs, int *count)
{
	char	*str;
	int		i;

	str = va_arg (vargs, char *);
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		(*count)++;
		i++;
	}
	return (*count);
}
