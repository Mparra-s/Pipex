/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:30:30 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/22 18:27:21 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*src;
	size_t			total_size;
	size_t			i;

	i = 0;
	if (size != 0 && nmemb >= __SIZE_MAX__ / size)
		return (NULL);
	total_size = nmemb * size;
	src = malloc(total_size);
	if (src == NULL)
		return (NULL);
	while (i < total_size)
	{
		src[i] = 0;
		i++;
	}
	return (src);
}

/*int main(void)
{
    int *arr;
    size_t i;
    size_t n = 5;

    // Reservamos memoria para 5 enteros
    arr = (int *)ft_calloc(n, sizeof(int));
    if (!arr)
    {
        printf("Error: No se pudo asignar memoria.\n");
        return (1);
    }

    // Mostramos los valores para comprobar que están en 0
    printf("Valores iniciales del array:\n");
    for (i = 0; i < n; i++)
        printf("arr[%zu] = %d\n", i, arr[i]);

    // Liberamos memoria
    free(arr);
    return (0);
}*/
