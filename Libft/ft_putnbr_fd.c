/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:16:06 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/18 09:06:53 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	nbr;
	long int		num;

	num = (long int) n;
	if (num < 0)
	{
		num = num * -1;
		write(fd, "-", 1);
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	nbr = (num % 10) + '0';
	write (fd, &nbr, 1);
}

/*int main(void)
{
    int number;
	int file;

	number = 0;
	file = open("Prueba.txt", O_WRONLY | O_CREAT | O_TRUNC, 0700 );
	ft_putnbr_fd(number, file);   
	close(file);
    return (0);
}*/
