/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc_fd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:47:23 by mparra-s          #+#    #+#             */
/*   Updated: 2025/06/10 11:10:17 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putc_fd2(char c, int fd)
{
	unsigned char	letter;

	letter = (unsigned char) c;
	write (fd, &c, 1);
}

/*int     main(void)
{
    char c;
	int file;

	c = 'W';
	file = open("Prueba.txt", O_WRONLY | O_CREAT | O_TRUNC, 0700 );
	ft_putchar_fd(c, file);
	close(file);
    return (0);
}*/
