/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:52:45 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/28 16:26:09 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stacks(t_list **lst_a, t_list **lst_b)
{
	int	current_el;

	// char	*op_name;
	while (*lst_a != NULL)
	{
		current_el = *(int *)(*lst_a)->content;
		while (*lst_b != NULL && current_el < *(int *)(*lst_b)->content)
		{
			// ft_printf("get into while into if\n");
			ft_printf("%s\n", push_b(lst_a, lst_b));
			ft_printf("%s\n", swap_b(lst_b));
			ft_printf("%s\n", push_a(lst_b, lst_a));
		}
		ft_printf("%s\n", push_b(lst_a, lst_b));
	}
	while (*lst_b != NULL)
		ft_printf("%s\n", push_a(lst_b, lst_a));
}

/*
input 7 1 6 5

1 call
current_el = 7
A	B
1	7
6
5

2 call
current_el = 1
A	B
6	1
5	7

3 call
current_el = 6
A	B
5	6
	1
	7

A	B
5	1

*/