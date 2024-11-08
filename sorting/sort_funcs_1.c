/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:45:18 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/08 12:04:08 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*rotate_a(t_dlist **lst)
{
	t_dlist	*second;
	t_dlist	*first;

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

char	*rotate_b(t_dlist **lst)
{
	t_dlist	*second;
	t_dlist	*first;

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

// char	*rotate_both(t_dlist **lst_a, t_dlist **lst_b)
// {
// 	char	*res;

// 	res = rotate_a(lst_a);
// 	if (res == 0)
// 		return ("rr");
// 	if (lst_b == NULL || *lst_b == NULL)
// 	{
// 		return ("rr");
// 	}
// 	res = rotate_b(lst_b);
// 	if (res == 0)
// 		return (0);
// 	return ("rr");
// }
