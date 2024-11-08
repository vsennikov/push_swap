/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:51:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/08 12:06:02 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_ordered(t_dlist **lst)
{
	t_dlist	*tmp;
	int		curr_index;

	tmp = *lst;
	curr_index = 0;
	while (tmp)
	{
		if (curr_index != tmp->index)
			return (0);
		curr_index++;
		tmp = tmp->next;
	}
	return (1);
}
