/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/02 12:55:46 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

void print_index_for_stack(d_list **lst)
{
	d_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("Value = %d, index = %d\n", *(int *)tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

int	max_index(d_list **lst)
{
	int		i;
	d_list	*tmp;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		if (tmp->index > i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

int	lowest_index(d_list **lst)
{
	int		i;
	d_list	*tmp;

	tmp = *lst;
	i = tmp->index;
	while (tmp)
	{
		if (tmp->index < i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

int	on_right_pos_a(d_list **lst)
{
	d_list	*tmp;
	d_list	*last_node;
	int		i;
	int		last_index;

	tmp = *lst;
	last_index = max_index(lst);
	last_node = ft_dlstlast(tmp);
	i = 0;
	// print_index_for_stack(lst);
	if (last_node->index != last_index)
		return (0);
	while (last_node && last_node->prev && last_node->index == last_node->prev->index + 1)
	{
		i++;
		last_node = last_node->prev;
	}
	if (i > 0)
		i++;
	// ft_printf("how many in a right order in a: %d\n", i);
	return (i);
}

int	on_right_pos_b(d_list **lst)
{
	d_list *tmp;
	d_list *last_node;
	int i;
	int first_index;

	tmp = *lst;
	first_index = 0;
	last_node = ft_dlstlast(tmp);
	i = 0;
	// print_index_for_stack(lst);
	if (last_node->index != first_index)
		return (0);
	while (last_node && last_node->prev && last_node->index == last_node->prev->index - 1)
	{
		i++;
		last_node = last_node->prev;
	}
	if (i > 0)
		i++;
	// ft_printf("how many in a right order in b: %d\n", i);
	return (i);
}
