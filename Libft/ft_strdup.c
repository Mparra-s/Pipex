/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:30:06 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/23 10:38:55 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*csrc;
	int		i;

	csrc = malloc(ft_strlen(src) + 1);
	if (csrc == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		csrc[i] = src[i];
		i++;
	}
	csrc[i] = '\0';
	return (csrc);
}

/*int	main(void)
{
	const char	src[] = "Hola mundo";

	printf("%s\n", ft_strdup(src));
	return (0);
}*/
