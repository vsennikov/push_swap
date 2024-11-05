/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:22:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:33 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

d_list	*ft_dlstnew(int	content, int index)
{
	d_list	*node;

	node = malloc(sizeof(d_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->index = index;
	return (node);
}

void	ft_dlstadd_front(d_list **lst, d_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

d_list	*ft_dlstlast(d_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_dlstadd_back(d_list **lst, d_list *new)
{
	d_list	*current;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = ft_dlstlast(*lst);
	current->next = new;
	new->prev = current;
}

int	ft_dlstsize(d_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
