/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:23:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/07 12:39:40 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	smallest_index(t_dlist **lst_a)
{
	t_dlist	*tmp;
	int		smallest;

	smallest = ft_dlstsize(*lst_a);
	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->index < smallest)
			smallest = tmp->index;
		tmp = tmp->next;
	}
	return (smallest);
}

static int	biggest_index(t_dlist **lst_a)
{
	t_dlist	*tmp;
	int		biggest;

	biggest = 0;
	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

void	sort_three(t_dlist **lst_a)
{
	int	smallest;
	int	biggest;

	smallest = smallest_index(lst_a);
	biggest = biggest_index(lst_a);
	if ((*lst_a)->index == smallest)
	{
		ft_printf("%s\n", swap_a(lst_a));
		ft_printf("%s\n", rotate_a(lst_a));
	}
	else if ((*lst_a)->index != smallest && (*lst_a)->index != biggest
		&& (*lst_a)->next->index == biggest)
		ft_printf("%s\n", reverse_rotate_a(lst_a));
	else if ((*lst_a)->index != smallest && (*lst_a)->index != biggest
		&& (*lst_a)->next->index == smallest)
		ft_printf("%s\n", swap_a(lst_a));
	else if ((*lst_a)->index == biggest && (*lst_a)->next->index == smallest)
		ft_printf("%s\n", rotate_a(lst_a));
	else
	{
		ft_printf("%s\n", rotate_a(lst_a));
		ft_printf("%s\n", swap_a(lst_a));
	}
}
