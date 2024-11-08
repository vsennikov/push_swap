/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/08 16:44:12 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_algo(t_dlist **lst, t_dlist **lst_b, int index_max)
{
	if (ft_dlstsize(*lst) == 3)
		sort_three(lst);
	else if (ft_dlstsize(*lst) == 4)
		sort_four(lst, lst_b);
	else if (ft_dlstsize(*lst) == 5)
		sort_five(lst, lst_b);
	else if (ft_dlstsize(*lst) > 5 && ft_dlstsize(*lst) < 500)
		chunk_sort(lst, lst_b, index_max, 15);
	else
		chunk_sort(lst, lst_b, index_max, 60);
}

int	main(int argc, char **argv)
{
	t_dlist	*lst;
	t_dlist	*lst_b;
	int		index_max;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		if (argv[1][0] == 0)
			exit_error();
	}
	lst = NULL;
	lst_b = NULL;
	check_style_pass_next(argc, argv, &lst);
	index_max = pre_sort(&lst, &lst_b);
	lst_b = NULL;
	if (check_if_ordered(&lst))
		return (ft_dlstclear(&lst, free), 0);
	choose_algo(&lst, &lst_b, index_max);
	return (ft_dlstclear(&lst, free), ft_dlstclear(&lst_b, free), 0);
}
