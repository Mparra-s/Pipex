/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:43:29 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/15 09:50:14 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int num)
{
	if (num > 47 && num < 58)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	number;

	number = '9';
	ft_isdigit (number);
	return (0);
}*/
