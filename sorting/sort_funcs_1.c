/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:45:18 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 13:14:49 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*rotate_a(d_list **lst)
{
	d_list	*second;
	d_list	*first;

	if ((*lst)->next == NULL)
		return ("ra");
	first = *lst;
	second = first->next;
	first->next = NULL;
	second->prev = NULL;
	*lst = second;
	ft_dlstadd_back(lst, first);
	return ("ra");
}

char	*rotate_b(d_list **lst)
{
	d_list	*second;
	d_list	*first;

	if ((*lst)->next == NULL)
		return ("rb");
	first = *lst;
	second = first->next;
	first->next = NULL;
	second->prev = NULL;
	*lst = second;
	ft_dlstadd_back(lst, first);
	return ("rb");
}

char	*rotate_both(d_list **lst_a, d_list **lst_b)
{
	char	*res;
	res = rotate_a(lst_a);
	if (res == 0)
		return ("rr");
	if (lst_b == NULL || *lst_b == NULL)
	{
		return ("rr");
	}
	res = rotate_b(lst_b);
	if (res == 0)
		return (0);
	return ("rr");
}
