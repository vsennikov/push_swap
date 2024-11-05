/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:11:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/05 15:05:48 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

int	max_index(t_dlist **lst)
{
	int		i;
	t_dlist	*tmp;

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

int	calculate_better_top(t_dlist **lst, int top_index)
{
	t_dlist	*top;
	int		i;

	top = *lst;
	i = 0;
	while (top)
	{
		if (top->index == top_index)
			break ;
		i++;
		top = top->next;
	}
	return (i);
}

int	calculate_better_bottom(t_dlist **lst, int bottom_index)
{
	t_dlist	*bottom;
	int		i;

	bottom = *lst;
	bottom = ft_dlstlast(bottom);
	i = 0;
	while (bottom)
	{
		if (bottom->index == bottom_index)
			break ;
		i++;
		bottom = bottom->prev;
	}
	return (i);
}

int	look_for_closer_index_top(t_dlist **lst, int start_range)
{
	t_dlist	*top;

	top = *lst;
	while (top)
	{
		if (top->index >= start_range && top->index < start_range + 5)
			break ;
		top = top->next;
	}
	return (top->index);
}

int	look_for_closer_index_bottom(t_dlist **lst, int start_range)
{
	t_dlist	*bottom;

	bottom = *lst;
	bottom = ft_dlstlast(bottom);
	while (bottom)
	{
		if (bottom->index >= start_range && bottom->index < start_range + 5)
			break ;
		bottom = bottom->prev;
	}
	return (bottom->index);
}
