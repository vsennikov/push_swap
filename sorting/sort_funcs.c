/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:34:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/05 18:12:11 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*swap_a(t_dlist **lst)
{
	t_dlist	*first;
	t_dlist	*second;

	if ((*lst)->next == NULL)
		return ("sa");
	first = *lst;
	second = (*lst)->next;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*lst = second;
	return ("sa");
}

char	*swap_b(t_dlist **lst)
{
	t_dlist	*first;
	t_dlist	*second;

	if ((*lst)->next == NULL)
		return ("sb");
	first = *lst;
	second = (*lst)->next;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*lst = second;
	return ("sb");
}

char	*swap_both(t_dlist **lst_a, t_dlist **lst_b)
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

char	*push_b(t_dlist **lst_a, t_dlist **lst_b)
{
	t_dlist	*first_a;
	t_dlist	*second_a;

	if (lst_a == NULL || *lst_a == NULL)
		return ("pb");
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
		if (*lst_b == NULL)
			sort_exit(lst_a);
		return ("pb");
	}
	ft_dlstadd_front(lst_b, first_a);
	return ("pb");
}

char	*push_a(t_dlist **lst_b, t_dlist **lst_a)
{
	t_dlist	*first_b;
	t_dlist	*second_b;

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
		if (*lst_a == NULL)
			sort_exit(lst_b);
		return ("pa");
	}
	ft_dlstadd_front(lst_a, first_b);
	return ("pa");
}
