/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:45:02 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/25 14:01:00 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	letters;

	letters = 0;
	while (*str != '\0')
	{
		letters++;
		str = str + 1;
	}
	return (letters);
}

/*int	main(void)
{
	const char	sentence[] = "Vamos a contar caracteres";

	ft_strlen(sentence);
	return (0);
}*/
