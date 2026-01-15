/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:59:17 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/18 09:03:34 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*void    ft_upper(unsigned int a, char *sentence)
{
    *sentence = ft_toupper(*sentence);
}*/

void	ft_striteri(char *str, void (*fun)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		fun(i, &str[i]);
		i++;
	}
}

/*int main(void)
{
    char    array[] = "hola mundo";
    ft_striteri(array, ft_upper);
    printf("%s", array);
    return (0);
}*/
