/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:21:46 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/05 15:05:36 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_back(t_dlist **lst_a, t_dlist **lst_b, int max_index)
{
	t_dlist	*tmp;
	int		size;
	int		r_counter;

	while (*lst_b)
	{
		tmp = *lst_b;
		size = ft_dlstsize(tmp);
		r_counter = 0;
		while (tmp->index != max_index)
		{
			r_counter++;
			tmp = tmp->next;
		}
		while ((*lst_b)->index != max_index)
		{
			if (r_counter < size / 2)
				ft_printf("%s\n", rotate_b(lst_b));
			else
				ft_printf("%s\n", reverse_rotate_b(lst_b));
		}
		max_index -= 1;
		ft_printf("%s\n", push_a(lst_b, lst_a));
	}
}

static void	call_rotate_or_reverse(t_dlist **lst_a, t_dlist **lst_b,
		int passed_index, int ra)
{
	if (ra)
	{
		while ((*lst_a)->index != passed_index)
			ft_printf("%s\n", rotate_a(lst_a));
		ft_printf("%s\n", push_b(lst_a, lst_b));
	}
	else
	{
		while ((*lst_a)->index != passed_index)
			ft_printf("%s\n", reverse_rotate_a(lst_a));
		ft_printf("%s\n", push_b(lst_a, lst_b));
	}
}

static void	mooving_stuff(t_dlist **lst_a, t_dlist **lst_b, int index)
{
	int	bottom_index;
	int	top_index;
	int	top_value;
	int	bottom_value;
	int	i;

	i = 0;
	while (*lst_a && i != 5)
	{
		top_index = look_for_closer_index_top(lst_a, index);
		top_value = calculate_better_top(lst_a, top_index);
		bottom_index = look_for_closer_index_bottom(lst_a, index);
		bottom_value = calculate_better_bottom(lst_a, bottom_index);
		if (top_value < bottom_value)
			call_rotate_or_reverse(lst_a, lst_b, top_index, 1);
		else
			call_rotate_or_reverse(lst_a, lst_b, bottom_index, 0);
		i++;
	}
}

void	chunk_sort(t_dlist **lst_a, t_dlist **lst_b, int max_index)
{
	int	index;

	index = 0;
	while (*lst_a)
	{
		mooving_stuff(lst_a, lst_b, index);
		index += 5;
	}
	push_back(lst_a, lst_b, max_index);
}
