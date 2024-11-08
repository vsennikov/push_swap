/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:44:41 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/08 12:04:14 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*reverse_rotate_a(t_dlist **lst)
{
	t_dlist	*copy;
	t_dlist	*last;

	if ((*lst)->next == NULL)
		return ("rra");
	copy = *lst;
	last = ft_dlstlast(*lst);
	while (copy->next->next != NULL)
		copy = copy->next;
	copy->next = NULL;
	ft_dlstadd_front(lst, last);
	return ("rra");
}

char	*reverse_rotate_b(t_dlist **lst)
{
	t_dlist	*copy;
	t_dlist	*last;

	if ((*lst)->next == NULL)
		return ("rrb");
	copy = *lst;
	last = ft_dlstlast(*lst);
	while (copy->next->next != NULL)
		copy = copy->next;
	copy->next = NULL;
	ft_dlstadd_front(lst, last);
	return ("rrb");
}

// char	*reverse_rotate_both(t_dlist **lst_a, t_dlist **lst_b)
// {
// 	char	*res;

// 	res = reverse_rotate_a(lst_a);
// 	if (res == 0)
// 		return ("rrr");
// 	res = reverse_rotate_b(lst_b);
// 	if (res == 0)
// 		return ("rrr");
// 	return ("rrr");
// }
