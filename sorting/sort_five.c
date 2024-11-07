/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:34:43 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/07 13:33:03 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ordered(t_dlist **lst)
{
	if ((*lst)->index < (*lst)->next->index
		&& (*lst)->next->index < (*lst)->next->next->index)
		return (1);
	return (0);
}

static void	reverse_or_rotate_five(t_dlist **lst)
{
	t_dlist	*tmp;
	int		r_counter;

	tmp = *lst;
	r_counter = 0;
	while (tmp->index != 0)
	{
		r_counter++;
		tmp = tmp->next;
	}
	while ((*lst)->index != 0)
	{
		if (r_counter < 3)
			ft_printf("%s\n", rotate_a(lst));
		else
			ft_printf("%s\n", reverse_rotate_a(lst));
	}
}

static void	hardcode_stuff(t_dlist **lst_a, t_dlist **lst_b)
{
	if ((*lst_b)->next->index == 4)
		ft_printf("%s\n", rotate_b(lst_b));
	if ((*lst_b) && (*lst_b)->index == 4)
	{
		ft_printf("%s\n", push_a(lst_b, lst_a));
		ft_printf("%s\n", rotate_a(lst_a));
	}
	if ((*lst_b)->next && (*lst_b)->next->index == 0)
		ft_printf("%s\n", rotate_b(lst_b));
	if ((*lst_b) && (*lst_b)->index == 0)
		ft_printf("%s\n", push_a(lst_b, lst_a));
	if ((*lst_b) && (*lst_b)->index == 1)
	{
		ft_printf("%s\n", push_a(lst_b, lst_a));
		ft_printf("%s\n", swap_a(lst_a));
	}
	if ((*lst_b) && (*lst_b)->next && (*lst_b)->index == 3
		&& (*lst_b)->next->index == 4)
	{
		ft_printf("%s\n", push_a(lst_b, lst_a));
		ft_printf("%s\n", swap_a(lst_a));
		ft_printf("%s\n", push_a(lst_b, lst_a));
		ft_printf("%s\n", swap_a(lst_a));
	}
}

void	sort_five(t_dlist **lst_a, t_dlist **lst_b)
{
	ft_printf("%s\n", push_b(lst_a, lst_b));
	ft_printf("%s\n", push_b(lst_a, lst_b));
	if (!ordered(lst_a))
		sort_three(lst_a);
	hardcode_stuff(lst_a, lst_b);
	if ((*lst_b) && (*lst_b)->next && ((*lst_b)->index == (*lst_b)->next->index
			+ 1))
		ft_printf("%s\n", swap_b(lst_b));
	while (*lst_b)
	{
		while ((*lst_b)->index - 1 != (*lst_a)->index)
			ft_printf("%s\n", rotate_a(lst_a));
		ft_printf("%s\n", push_a(lst_b, lst_a));
		ft_printf("%s\n", swap_a(lst_a));
	}
	if ((*lst_a)->index != 0)
		reverse_or_rotate_five(lst_a);
}
