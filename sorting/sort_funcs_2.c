/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:44:41 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/28 12:47:58 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*reverse_rotate_a(t_list **lst)
{
	t_list	*copy;
	t_list	*last;
	
	if ((*lst)->next == NULL)
		return (0);
	copy = *lst;
	last = ft_lstlast(*lst);
	while (copy->next->next != NULL)
		copy = copy->next;
	copy->next = NULL;
	ft_lstadd_front(lst, last);
	return ("rra");
}

char	*reverse_rotate_b(t_list **lst)
{
	t_list	*copy;
	t_list	*last;
	
	if ((*lst)->next == NULL)
		return (0);
	copy = *lst;
	last = ft_lstlast(*lst);
	while (copy->next->next != NULL)
		copy = copy->next;
	copy->next = NULL;
	ft_lstadd_front(lst, last);
	return ("rrb");
}

char	*reverse_rotate_both(t_list **lst_a, t_list **lst_b)
{
	char	*res;
	res = reverse_rotate_a(lst_a);
	if (res == 0)
		return (0);
	res = reverse_rotate_b(lst_b);
	if (res == 0)
		return (0);
	return ("rrb");
}
