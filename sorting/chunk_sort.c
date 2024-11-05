/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:21:46 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/05 13:04:24 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_chunks(d_list **lst)
{
	int		size;
	d_list	*tmp;

	tmp = *lst;
	size = ft_dlstsize(tmp);
	if (size <= 3)
		return (0);
	if (size > 3 && size <= 5)
		return (1);
	if (size % 5 == 0)
		return (size / 5);
	else
		return (size / 5 + 1);
}

int	calculate_better_top(d_list **lst, int top_index)
{
	d_list	*top;
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

int	calculate_better_bottom(d_list **lst, int bottom_index)
{
	d_list	*bottom;
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

int	look_for_closer_index_top(d_list **lst, int start_range)
{
	d_list	*top;

	top = *lst;
	while (top)
	{
		if (top->index >= start_range && top->index < start_range + 5)
			break ;
		top = top->next;
	}
	return (top->index);
}

int	look_for_closer_index_bottom(d_list **lst, int start_range)
{
	d_list	*bottom;

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

void	push_back(d_list **lst_a, d_list **lst_b, int max_index)
{
	d_list	*tmp;
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

void	chunk_sort(d_list **lst_a, d_list **lst_b, int max_index)
{
	int	bottom_index;
	int	top_index;
	int	index;
	int	top_value;
	int	bottom_value;
	int	i;

	index = 0;
	while (*lst_a)
	{
		i = 0;
		while (i != 5)
		{
			top_index = look_for_closer_index_top(lst_a, index);
			top_value = calculate_better_top(lst_a, top_index);
			bottom_index = look_for_closer_index_bottom(lst_a, index);
			bottom_value = calculate_better_bottom(lst_a, bottom_index);
			if (top_value < bottom_value)
			{
				while ((*lst_a)->index != top_index)
					ft_printf("%s\n", rotate_a(lst_a));
				ft_printf("%s\n", push_b(lst_a, lst_b));
			}
			else
			{
				while ((*lst_a)->index != bottom_index)
					ft_printf("%s\n", reverse_rotate_a(lst_a));
				ft_printf("%s\n", push_b(lst_a, lst_b));
			}
			i++;
		}
		index += 5;
	}
	push_back(lst_a, lst_b, max_index);
}

// void    sort_stacks(d_list lst_a, d_list lst_b)
// {
//     int        smallest;
//     d_list    tmp;
//     int        size;
//     int        r_counter;

//     if (ordered(lst_a))
//         return ;
//     while (lst_a != NULL)
//     {
//         r_counter = 0;
//         size = ft_dlstsize(lst_a);
//         tmp =lst_a;
//         smallest = (int)tmp->content;
//         while (tmp != NULL)
//         {
//             if ((int)tmp->content < smallest)
//                 smallest = (int)tmp->content;
//             tmp = tmp->next;
//             r_counter++;
//         }
//         while ((int)(lst_a)->content != smallest)
//         {
//             if (size / 2 <= r_counter)
//                 ft_printf("%s\n", rotate_a(lst_a));
//             else
//                 ft_printf("%s\n", reverse_rotate_a(lst_a));
//         }
//         ft_printf("%s\n", push_b(lst_a, lst_b));
//     }
//     while (lst_b != NULL)
//         ft_printf("%s\n", push_a(lst_b, lst_a));
// }