/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:52:45 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 11:49:10 by vsenniko         ###   ########.fr       */
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

// void printlst_int_in(d_list *lst)
// {
// 	while (lst)
// 	{
// 		ft_printf("value = %d, index = %d\n", *(int *)(lst->content), lst->index);
// 		lst = (lst)->next;
// 	}
// }
static int	ordered(d_list **lst)
{
	d_list	*tmp;

	tmp = *lst;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
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
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
// quick_v2

static void	sort_to_stack_b(d_list **lst_a, d_list **lst_b, int max_index)
{
	int	pivot;
	int	top_b;
	int	i;
	int	allowed_moves;

	pivot = (*lst_a)->content;
	ft_printf("%s\n", push_b(lst_a, lst_b));
	allowed_moves = ft_dlstsize(*lst_a) - on_right_pos_a(lst_a, max_index);
	i = 0;
	// ft_printf("allowed moves for sort_to_b = %d\n", allowed_moves);
	while (*lst_a && i != allowed_moves)
	{
		top_b = (*lst_b)->content;
		ft_printf("%s\n", push_b(lst_a, lst_b));
		if ((*lst_b)->content < pivot)
			ft_printf("%s\n", rotate_b(lst_b));
		if (top_b > (*lst_b)->content)
			ft_printf("%s\n", swap_b(lst_b));
		i++;
	}
	if (ordered(lst_a) && ordered_reversed(lst_b))
	{
		while (*lst_b)
			ft_printf("%s\n", push_a(lst_b, lst_a));
	}
}

static void	sort_to_stack_a(d_list **lst_a, d_list **lst_b)
{
	int	pivot;
	int	top_a;
	int	i;
	int	allowed_moves;

	pivot = (*lst_b)->content;
	ft_printf("%s\n", push_a(lst_b, lst_a));
	i = 0;
	allowed_moves = ft_dlstsize(*lst_b) - on_right_pos_b(lst_b);
	// ft_printf("allowed moves for sort_to_a = %d", allowed_moves);
	while (*lst_b && i != allowed_moves)
	{
		top_a = (*lst_a)->content;
		ft_printf("%s\n", push_a(lst_b, lst_a));
		if ((*lst_a)->content > pivot)
			ft_printf("%s\n", rotate_a(lst_a));
		if (top_a < (*lst_a)->content)
			ft_printf("%s\n", swap_a(lst_a));
		i++;
	}
		if (ordered(lst_a) && ordered_reversed(lst_b))
	{
		while (*lst_b)
			ft_printf("%s\n", push_a(lst_b, lst_a));
	}
}

void	sort_stacks(d_list **lst_a, d_list **lst_b, int max_index)
{
	while (!ordered(lst_a))
	{
		// ft_printf("lst a before:\n");
		// printlst_int_in(*lst_a);
		sort_to_stack_b(lst_a, lst_b, max_index);
		// ft_printf("lst a after sort to stack b:\n");
		// printlst_int_in(*lst_a);
		// ft_printf("lst b after sort to stack b:\n");
		// printlst_int_in(*lst_b);
		if (ordered_reversed(lst_b))
		{
			while (*lst_b)
				ft_printf("%s\n", push_a(lst_b, lst_a));
			break ;
		}
		sort_to_stack_a(lst_a, lst_b);
		// ft_printf("lst a after sort to stack a:\n");
		// printlst_int_in(*lst_a);
		// ft_printf("lst b after sort to stack a:\n");
		// printlst_int_in(*lst_b);
	}
}
