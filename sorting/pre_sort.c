/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:51:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/05 18:28:38 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	create_copy_for_sort(t_dlist **lst, t_dlist **copy)
{
	t_dlist	*current;
	t_dlist	*node;

	*copy = ft_dlstnew((*lst)->content, (*lst)->index);
	if (*copy == NULL)
	{
		ft_dlstclear(lst, free);
		exit_error();
	}
	current = (*lst)->next;
	while (current)
	{
		node = ft_dlstnew(current->content, current->index);
		if (node == NULL)
		{
			ft_dlstclear(lst, free);
			ft_dlstclear(copy, free);
			exit_error();
		}
		ft_dlstadd_back(copy, node);
		current = current->next;
	}
}

static void	assigned_index(t_dlist **lst_a, t_dlist **copy)
{
	t_dlist	*current_a;
	t_dlist	*current_c;
	int		i;

	current_c = *copy;
	i = 0;
	while (current_c)
	{
		current_a = *lst_a;
		while (current_a->content != current_c->content)
			current_a = current_a->next;
		current_a->index = i;
		i++;
		current_c = current_c->next;
	}
}

int	pre_sort(t_dlist **lst_a, t_dlist **lst_b)
{
	t_dlist	*current;
	int		smallest;
	t_dlist	*tmp;

	create_copy_for_sort(lst_a, &current);
	while (current != NULL)
	{
		tmp = current;
		smallest = tmp->content;
		while (tmp != NULL)
		{
			if (tmp->content < smallest)
				smallest = tmp->content;
			tmp = tmp->next;
		}
		while (current->content != smallest)
			rotate_a(&current);
		push_b(&current, lst_b);
	}
	while (*lst_b != NULL)
		push_a(lst_b, &current);
	assigned_index(lst_a, &current);
	ft_dlstclear(&current, free);
	return (max_index(lst_a));
}
