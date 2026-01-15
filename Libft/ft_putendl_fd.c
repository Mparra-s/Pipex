/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:10:01 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/18 09:11:13 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	unsigned char	*cstr;
	int				i;

	cstr = (unsigned char *)str;
	i = 0;
	while (cstr[i] != '\0')
	{
		write(fd, &cstr[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*int main(void)
{
    char *sentence;
	int file;

	sentence = "Hola mundo";
	file = open("Prueba.txt", O_WRONLY | O_CREAT | O_TRUNC, 0700);
	ft_putendl_fd(sentence, file);
	close(file);
    return (0);
}*/
