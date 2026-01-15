/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:45:54 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/16 09:36:33 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int letter)
{
	unsigned char	c;

	c = (unsigned char)letter;
	if (c > 96 && c < 123)
	{
		c = c - 32;
		return (c);
	}
	else
		return (letter);
}

/*int	main(void)
{
 	int	letter;

 	letter = 'a';
 	printf("%c", ft_toupper (letter));
 	return (0);
}*/
