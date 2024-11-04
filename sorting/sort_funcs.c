/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:34:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 12:36:24 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*swap_a(d_list **lst)
{
	d_list	*first;
	d_list	*second;

	if ((*lst)->next == NULL)
		return (0);
	first = *lst;
	second = (*lst)->next;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*lst = second;
	return ("sa");
}

char	*swap_b(d_list **lst)
{
	d_list	*first;
	d_list	*second;

	if ((*lst)->next == NULL)
		return (0);
	first = *lst;
	second = (*lst)->next;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*lst = second;
	return ("sb");
}

char	*swap_both(d_list **lst_a, d_list **lst_b)
{
	char	*res;

	res = swap_a(lst_a);
	if (res == NULL)
		return (res);
	res = swap_b(lst_b);
	if (res == NULL)
		return (res);
	return ("ss");
}

char	*push_b(d_list **lst_a, d_list **lst_b)
{
	d_list	*first_a;
	d_list	*second_a;

	if (lst_a == NULL || *lst_a == NULL)
		return (0);
	first_a = *lst_a;
	if (first_a->next != NULL)
	{
		second_a = first_a->next;
		second_a->prev = NULL;
		*lst_a = second_a;
	}
	else
		*lst_a = NULL;
	if (*lst_b == NULL)
	{
		*lst_b = ft_dlstnew(first_a->content, first_a->index);
		if (lst_b == NULL)
		{
			ft_dlstclear(lst_a, free);
			exit_error();
		}
		return ("pb");
	}
	ft_dlstadd_front(lst_b, first_a);
	return ("pb");
}

char	*push_a(d_list **lst_b, d_list **lst_a)
{
	d_list	*first_b;
	d_list	*second_b;

	if (lst_b == NULL || *lst_b == NULL)
		return (0);
	first_b = *lst_b;
	if (first_b->next != NULL)
	{
		second_b = first_b->next;
		second_b->prev = NULL;
		*lst_b = second_b;
	}
	else 
		*lst_b = NULL;
	if (*lst_a == NULL)
	{
		*lst_a = ft_dlstnew(first_b->content, first_b->index);
		if (lst_a == NULL)
		{
			ft_dlstclear(lst_b, free);
			exit_error();
		}
		return ("pa");
	}
	ft_dlstadd_front(lst_a, first_b);
	return ("pa");
}
