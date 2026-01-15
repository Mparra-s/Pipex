/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:24:16 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/23 10:19:22 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*sentence;

	sentence = (t_list *)malloc(sizeof (t_list));
	if (sentence == NULL)
		return (NULL);
	sentence->content = content;
	sentence->next = NULL;
	return (sentence);
}
