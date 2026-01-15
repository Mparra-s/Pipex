/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:07:03 by mparra-s          #+#    #+#             */
/*   Updated: 2025/07/22 12:04:45 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_letters(char *str, char letter)
{
	int	count_words;
	int	is_word;
	int	a;

	count_words = 0;
	is_word = 0;
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] != letter && is_word == 0)
		{
			is_word = 1;
			count_words++;
		}
		if (str[a] == letter)
			is_word = 0;
		a++;
	}
	return (count_words);
}

static char	**ft_words_array(char *str, char letter, char **matrix)
{
	size_t	i;
	size_t	i_line;
	size_t	i_word;

	i_line = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i_word = 1;
		if (str[i] != letter)
		{
			while ((str[i + i_word] != '\0') && (str[i + i_word] != letter))
				i_word++;
			matrix[i_line++] = ft_substr(str, i, i_word);
			if (matrix[i_line - 1] == NULL)
			{
				while (i_line-- > 0)
					free(matrix[i_line]);
				free(matrix);
				return (NULL);
			}
		}
		i = i + i_word;
	}
	return (matrix);
}

char	**ft_split(char const *str, char letter)
{
	char	**matrix;
	char	*sentence;
	size_t	counter_words;

	sentence = (char *)str;
	counter_words = ft_letters(sentence, letter);
	matrix = (char **)malloc(sizeof(char *) * (counter_words + 1));
	if (matrix == NULL)
		return (NULL);
	if (counter_words == 0)
	{
		matrix[0] = NULL;
		return (matrix);
	}
	if ((ft_words_array(sentence, letter, matrix)) != NULL)
	{
		matrix[counter_words] = NULL;
		return (matrix);
	}
	free(matrix);
	return (NULL);
}

/*int	main(void)
{
	char const	Lista [] = "Tomates pimientos carne y pescado";
	char	separador = ' ';
	char	**split_devuelto;
	size_t	i;

   	split_devuelto = ft_split(Lista, separador);
    i = 0;
	while (split_devuelto[i] != NULL)
	{
		printf("%s\n", split_devuelto[i]);
		i++;
	}
    free(split_devuelto);
	return (0);
}*/
