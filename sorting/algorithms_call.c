/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:52:45 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/01 12:15:04 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 				ft_printf("%s\n", push_a(lst_b, lst_a));

int	ordered(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// void	sort_stacks(t_list **lst_a, t_list **lst_b)
// {
// 	int		smallest;
// 	t_list	*tmp;
// 	int		size;
// 	int		r_counter;

// 	if (ordered(lst_a))
// 		return ;
// 	while (*lst_a != NULL)
// 	{
// 		r_counter = 0;
// 		size = ft_lstsize(*lst_a);
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

int	has_bigger(int curr_el, t_list **lst)
{
	t_list	*tmp;
	int		counter;

	tmp = *lst;
	counter = 0;
	while (tmp != NULL)
	{
		if (*(int *)tmp->content >= curr_el)
			counter++;
		tmp = tmp->next;
	}
	if (counter == ft_lstsize(*lst))
		return (1);
	return (0);
}
// quick_v2
void	sort_stacks(t_list **lst_a, t_list **lst_b)
{
	int	pivot;

	if (ordered(lst_a) || *lst_a == NULL)
		return ;
	pivot = *(int *)(*lst_a)->content;
	ft_printf("%s\n", push_b(lst_a, lst_b));
	while (*lst_a)
	{
		if (*(int *)(*lst_a)->content > pivot)
			ft_printf("%s\n", push_b(lst_a, lst_b));
		else
		{
			ft_printf("%s\n", push_b(lst_a, lst_b));
			ft_printf("%s\n", rotate_b(lst_b));
		}
		sort_stacks(lst_b, lst_a);
		sort_stacks(lst_a, lst_b);
		while (*lst_b)
			ft_printf("%s\n", push_a(lst_b, lst_a));
	}
}

// quick
// void	sort_stacks(t_list **lst_a, t_list **lst_b)
// {
// 	int	curr_el;
// 	int		i;
// 	int		size;

// 	if (ordered(lst_a) || *lst_a == NULL || (*lst_a)->next == NULL)
// 		return ;
// 	curr_el = *(int *)(*lst_a)->content;
// 	size = ft_lstsize(*lst_a);
// 	i = 0;
// 	while (i != size)
// 	{
// 		if (*(int *)(*lst_a)->content < curr_el)
// 			ft_printf("%s\n", push_b(lst_a, lst_b));
// 		else
// 			ft_printf("%s\n", rotate_a(lst_a));
// 		i++;
// 	}
// 	sort_stacks(lst_a, lst_b);
// 	sort_stacks(lst_b, lst_a);
// 	while (*lst_b != NULL)
// 		ft_printf("%s\n", push_a(lst_b, lst_a));
// }
