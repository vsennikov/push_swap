/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:34:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/25 17:33:28 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if ((*lst)->next == NULL)
		return (1);
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	return (1);
}

int	swap_both(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	return (1);
}

int	push(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_a;
	t_list	*second_a;

	first_a = *lst_a;
	second_a = first_a->next;
	*lst_a = second_a;
	if(*lst_b == NULL)
	{
		*lst_b = ft_lstnew(first_a->content);
		if (lst_b == NULL)
		{
			ft_lstclear(lst_a, free);
			exit_error();
		}
		return (1);
	}
	ft_lstadd_front(lst_b, first_a);
	return (1);
}

int	rotate(t_list **lst)
{
	t_list	*second;
	t_list	*first;

	if ((*lst)->next == NULL)
		return (1);
	first = *lst;
	second = first->next;
	first->next = NULL;
	*lst = second;
	ft_lstadd_back(lst, first);
	return (1);
}

int	rotate_both(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	if (lst_b == NULL || *lst_b == NULL)
	{
		ft_lstclear(lst_a, free);
		exit_error();
	}
	rotate(lst_b);
	return (1);
}

int	reverse_rotate(t_list **lst)
{
	t_list	*copy;
	t_list	*last;
	
	if ((*lst)->next == NULL)
		return (1);
	copy = *lst;
	last = ft_lstlast(*lst);
	while (copy->next->next != NULL)
		copy = copy->next;
	copy->next = NULL;
	ft_lstadd_front(lst, last);
	return (1);
}

int	reverse_rotate_both(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	return (1);
}