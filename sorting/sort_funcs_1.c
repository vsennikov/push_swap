/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:45:18 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/28 12:47:49 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*rotate_a(t_list **lst)
{
	t_list	*second;
	t_list	*first;

	if ((*lst)->next == NULL)
		return (0);
	first = *lst;
	second = first->next;
	first->next = NULL;
	*lst = second;
	ft_lstadd_back(lst, first);
	return ("ra");
}

char	*rotate_b(t_list **lst)
{
	t_list	*second;
	t_list	*first;

	if ((*lst)->next == NULL)
		return (0);
	first = *lst;
	second = first->next;
	first->next = NULL;
	*lst = second;
	ft_lstadd_back(lst, first);
	return ("rb");
}

char	*rotate_both(t_list **lst_a, t_list **lst_b)
{
	char	*res;
	res = rotate_a(lst_a);
	if (res == 0)
		return (0);
	if (lst_b == NULL || *lst_b == NULL)
	{
		return (0);
	}
	res = rotate_b(lst_b);
	if (res == 0)
		return (0);
	return ("rr");
}
