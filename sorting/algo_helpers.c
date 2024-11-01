/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/01 19:37:12 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

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

int	how_many_mooves_a(d_list **lst)
{
	d_list	*tmp;
	d_list	*last_node;
	int		i;
	int		last_index;

	tmp = *lst;
	last_index = max_index(lst);
	last_node = ft_dlstlast(tmp);
	i = 0;
	while (last_node && last_node->prev && last_node->index == last_node->prev->index + 1)
	{
		i++;
		last_node = last_node->prev;
	}
	return (i - 1);
}

int	how_many_mooves_b(d_list **lst)
{
	d_list *tmp;
	d_list *last_node;
	int i;
	int first_index;

	tmp = *lst;
	first_index = lowest_index(lst);
	last_node = ft_dlstlast(tmp);
	i = 0;
	while (last_node && last_node->prev && last_node->index == last_node->prev->index - 1)
	{
		i++;
		last_node = last_node->prev;
	}

	return (i - 1);
}
