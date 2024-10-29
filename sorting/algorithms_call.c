/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:52:45 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/29 15:09:35 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 				ft_printf("%s\n", push_a(lst_b, lst_a));

int	ordered(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (*(int *)tmp->content > *(int*)tmp->next->content)
			return(0);
		tmp = tmp->next;	
	}
	return (1);
}

void	sort_stacks(t_list **lst_a, t_list **lst_b)
{
	int	curr_el;
	int		i;
	int		size;
	
	if (ordered(lst_a) || *lst_a == NULL)
		return ;
	curr_el = *(int *)(*lst_a)->content;
	size = ft_lstsize(*lst_a);
	i = 0;
	while (i != size)
	{
		if (*(int *)(*lst_a)->content < curr_el)
			ft_printf("%s\n", push_b(lst_a, lst_b));
		else
			ft_printf("%s\n", rotate_a(lst_a));
		i++;
	}
	ft_printf("call sort_stacks for a\n");
	sort_stacks(lst_a, lst_b);	
	ft_printf("call sort_stacks for b\n");
	sort_stacks(lst_b, lst_a);
	while (*lst_b != NULL)
		ft_printf("%s\n", push_a(lst_b, lst_a));
}
