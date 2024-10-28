/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:34:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/28 13:53:20 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*swap_a(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if ((*lst)->next == NULL)
		return (0);
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	return ("sa");
}

char	*swap_b(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if ((*lst)->next == NULL)
		return (0);
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	return ("sb");
}

char	*swap_both(t_list **lst_a, t_list **lst_b)
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

char	*push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*first_a;
	t_list	*second_a;

	if (lst_a == NULL || *lst_a == NULL)
		return (0);
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
		return ("pb");
	}
	ft_lstadd_front(lst_b, first_a);
	return ("pb");
}

char	*push_a(t_list **lst_b, t_list **lst_a)
{
	t_list	*first_b;
	t_list	*second_b;

	if (lst_b == NULL || *lst_b == NULL)
		return (0);
	first_b = *lst_b;
	second_b = first_b->next;
	*lst_b = second_b;
	if(*lst_a == NULL)
	{
		*lst_a = ft_lstnew(first_b->content);
		if (lst_a == NULL)
		{
			ft_lstclear(lst_b, free);
			exit_error();
		}
		return ("pa");
	}
	ft_lstadd_front(lst_a, first_b);
	return ("pa");
}
