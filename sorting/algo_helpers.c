/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 13:13:56 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

void	print_index_for_stack(d_list **lst)
{
	d_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("Value = %d, index = %d\n", tmp->content, tmp->index);
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

int	on_right_pos_a(d_list **lst, int max_index)
{
	d_list	*tmp;
	d_list	*last_node;
	int		i;

	tmp = *lst;
	last_node = ft_dlstlast(tmp);
	i = 1;
	if (last_node->index != max_index)
		return (0);
	while (last_node && last_node->prev
		&& last_node->index == (last_node->prev->index + 1))
	{
		i++;
		last_node = last_node->prev;
	}
	return (i);
}

int	on_right_pos_b(d_list **lst)
{
	d_list	*tmp;
	d_list	*last_node;
	int		i;
	int		first_index;

	tmp = *lst;
	first_index = 0;
	last_node = ft_dlstlast(tmp);
	i = 1;
	if (last_node->index != first_index)
		return (0);
	while (last_node && last_node->prev
		&& last_node->index == last_node->prev->index - 1)
	{
		i++;
		last_node = last_node->prev;
	}
	return (i);
}
