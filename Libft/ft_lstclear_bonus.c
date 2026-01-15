/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <mparra-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:26:32 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/23 09:45:40 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		aux = (*lst)->next;
		del ((*lst)->content);
		free (*lst);
		*lst = aux;
	}
}
