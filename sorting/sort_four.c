/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:33:21 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/08 12:06:41 by vsenniko         ###   ########.fr       */
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

void	sort_four(t_dlist **lst_a, t_dlist **lst_b)
{
	ft_printf("%s\n", push_b(lst_a, lst_b));
	if (!ordered(lst_a))
		sort_three(lst_a);
	while ((*lst_b))
	{
		while ((*lst_a)->index + 1 != (*lst_b)->index && (*lst_a)->index
			- 1 != (*lst_b)->index)
			ft_printf("%s\n", rotate_a(lst_a));
		ft_printf("%s\n", push_a(lst_b, lst_a));
		if ((*lst_a)->index > (*lst_a)->next->index)
			ft_printf("%s\n", swap_a(lst_a));
	}
	while ((*lst_a)->index != 0)
		ft_printf("%s\n", rotate_a(lst_a));
}
