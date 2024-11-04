/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_double_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:30:20 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 11:33:52 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_dlstdelone(d_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	// del(lst->content);
	del(lst);
}

void	ft_dlstclear(d_list **lst, void (*del)(void*))
{
	d_list	*current;
	d_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		ft_dlstdelone(tmp, del);
	}
	*lst = NULL;
}
