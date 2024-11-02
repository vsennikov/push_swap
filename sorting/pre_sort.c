/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:51:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/02 12:35:58 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	create_copy_for_sort(d_list **lst, d_list **copy)
{
	d_list	*current;
	d_list	*node;

	*copy = ft_dlstnew((*lst)->content);
	if (*copy == NULL)
	{
		ft_dlstclear(lst, free);
		exit_error();
	}
	current = (*lst)->next;
	while (current)
	{
		node = ft_dlstnew(current->content);
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
void print_index_for_stack1(d_list **lst)
{
	d_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("After presort Value = %d, index = %d\n", *(int *)tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

static void	assigned_index(d_list **lst_a, d_list **copy)
{
	d_list	*current_a;
	d_list	*current_c;
	int		i;

	current_c = *copy;
	i = 0;
	while (current_c)
	{
		current_a = *lst_a;
		while (*(int *)current_a->content != *(int *)current_c->content)
			current_a = current_a->next;
		current_a->index = i;
		i++;
		current_c = current_c->next;
	}
	// print_index_for_stack1(lst_a);
}

void	pre_sort(d_list **lst_a, d_list **lst_b)
{
	d_list	*current;
	int		smallest;
	d_list	*tmp;

	create_copy_for_sort(lst_a, &current);
	while (current != NULL)
	{
		tmp = current;
		smallest = *(int *)tmp->content;
		while (tmp != NULL)
		{
			if (*(int *)tmp->content < smallest)
				smallest = *(int *)tmp->content;
			tmp = tmp->next;
		}
		while (*(int *)current->content != smallest)
			rotate_a(&current);
		push_b(&current, lst_b);
	}
	while (*lst_b != NULL)
		push_a(lst_b, &current);
	assigned_index(lst_a, &current);
	// ft_dlstclear(&current, free);
}
