/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:26:36 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/23 10:33:23 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr [i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}

/*int	main (void)
{
	const char	nptr[] = "       +-23456abc";

	ft_atoi(nptr);
	return (0);
}*/
