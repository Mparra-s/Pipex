/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:48:13 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/23 10:36:05 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_count(int n)
{
	long int	count;
	long int	num;

	count = 0;
	num = (long int)n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	long int	len;
	char		*str;

	nbr = (long int)n;
	len = ft_count(n);
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/*long int     ft_count(int n)
{
    long int count;
    long int a;

    a = (long int)n;
    count = 0;
    if (a < 0)
    {
        a = -a;
        count++;
    }
    while (a)
    {
        a /= 10;
        count++;
    }
    return (count);

}

char    *ft_itoa(int n)
{
    char *number;
    int sign;
    long int i;

    i = ft_count((long int)n);
    sign = 0;
    if (n < 0)
    {
        n = n * -1;
        sign = 1;
    }
    number = malloc(ft_count(n) + 1);
    number[i] = '\0';
    if (number == NULL)
        return (NULL);
    while (i > 0)
    {        
        i--;
        number[i] = (n % 10) + '0';
        n /= 10;
    }
    if(sign == 1)
            number[0] = '-';
    return(number);
}*/

// int main(void)
// {
//     int number;
//     char *res;
//     number  = -2147483648;
//     res = ft_itoa(number);
//     printf("%s\n", res);
//     return (0);
// }
