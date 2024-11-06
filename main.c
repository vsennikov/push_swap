/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/06 15:54:16 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_dlist **lst)
{
	t_dlist	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("value = %d, index = %d\n", tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*lst;
	t_dlist	*lst_b;
	int		index_max;

	if (argc < 2)
		return (1);
	lst = NULL;
	lst_b = NULL;
	check_style_pass_next(argc, argv, &lst);
	index_max = pre_sort(&lst, &lst_b);
	lst_b = NULL;
	if (check_if_ordered(&lst))
		return(	ft_dlstclear(&lst, free), 0);
	if (ft_dlstsize(lst) < 500)
		chunk_sort(&lst, &lst_b, index_max, 15);
	else
		chunk_sort(&lst, &lst_b, index_max, 60);
	ft_dlstclear(&lst, free);
	ft_dlstclear(&lst_b, free);
	return (0);
}
