/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:52:45 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/01 19:34:39 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 2000+ operations
//
// void	sort_stacks(d_list **lst_a, d_list **lst_b)
// {
// 	int		smallest;
// 	d_list	*tmp;
// 	int		size;
// 	int		r_counter;

// 	if (ordered(lst_a))
// 		return ;
// 	while (*lst_a != NULL)
// 	{
// 		r_counter = 0;
// 		size = ft_dlstsize(*lst_a);
// 		tmp = *lst_a;
// 		smallest = *(int *)tmp->content;
// 		while (tmp != NULL)
// 		{
// 			if (*(int *)tmp->content < smallest)
// 				smallest = *(int *)tmp->content;
// 			tmp = tmp->next;
// 			r_counter++;
// 		}
// 		while (*(int *)(*lst_a)->content != smallest)
// 		{
// 			if (size / 2 <= r_counter)
// 				ft_printf("%s\n", rotate_a(lst_a));
// 			else
// 				ft_printf("%s\n", reverse_rotate_a(lst_a));
// 		}
// 		ft_printf("%s\n", push_b(lst_a, lst_b));
// 	}
// 	while (*lst_b != NULL)
// 		ft_printf("%s\n", push_a(lst_b, lst_a));
// }

static int	ordered(d_list **lst)
{
	d_list	*tmp;

	tmp = *lst;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ordered_reversed(d_list **lst)
{
	d_list	*tmp;

	tmp = *lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
// quick_v2

static void	sort_to_stack_b(d_list **lst_a, d_list **lst_b)
{
	int	pivot;
	int	top_b;
	int	i;
	int	allowed_moves;

	pivot = *(int *)(*lst_a)->content;
	ft_printf("%s\n", push_b(lst_a, lst_b));
	allowed_moves = ft_dlstsize(*lst_a) - how_many_mooves_a(lst_a);
	i = 0;
	while (*lst_a && i != allowed_moves)
	{
		top_b = *(int *)(*lst_b)->content;
		ft_printf("%s\n", push_b(lst_a, lst_b));
		if (*(int *)(*lst_b)->content < pivot)
			ft_printf("%s\n", rotate_b(lst_b));
		if (top_b > *(int *)(*lst_b)->content)
			ft_printf("%s\n", swap_b(lst_b));
		i++;
	}
}

static void	sort_to_stack_a(d_list **lst_a, d_list **lst_b)
{
	int	pivot;
	int	top_a;
	int	i;
	int	allowed_moves;

	pivot = *(int *)(*lst_b)->content;
	ft_printf("%s\n", push_a(lst_b, lst_a));
	allowed_moves = ft_dlstsize(*lst_b) - how_many_mooves_b(lst_b);
	i = 0;
	while (*lst_b && i != allowed_moves)
	{
		top_a = *(int *)(*lst_a)->content;
		ft_printf("%s\n", push_a(lst_b, lst_a));
		if (*(int *)(*lst_a)->content > pivot)
			ft_printf("%s\n", rotate_a(lst_a));
		if (top_a < *(int *)(*lst_a)->content)
			ft_printf("%s\n", swap_a(lst_a));
		i++;
	}
}

void	sort_stacks(d_list **lst_a, d_list **lst_b)
{
	while (!ordered(lst_a))
	{
		sort_to_stack_b(lst_a, lst_b);
		if (ordered_reversed(lst_b))
		{
			while (*lst_b)
				ft_printf("%s\n", push_a(lst_b, lst_a));
			break ;
		}
		sort_to_stack_a(lst_a, lst_b);
	}
}
