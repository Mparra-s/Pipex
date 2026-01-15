/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:32:15 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/18 08:59:29 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	unsigned char	*cstr;
	int				i;

	cstr = (unsigned char *)str;
	i = 0;
	while (cstr[i] != '\0')
	{
		write (fd, &cstr[i], 1);
		i++;
	}
}

/*int main(void)
{
    char sentence[] = "Hola mundo";
    int file;

    file = open("Prueba.txt", O_WRONLY | O_RDONLY | O_TRUNC, 0700);
    ft_putstr_fd(sentence, file);
    close (file);
    return (0);
}*/
