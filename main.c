/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/05 13:00:34 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	d_list	*lst;
	d_list	*lst_b;
	int		index_max;
	
	if (argc < 2)
		return (1);
	lst = NULL;
	lst_b = NULL;
	check_style_pass_next( argc, argv, &lst);
	index_max = pre_sort(&lst, &lst_b);
	lst_b = NULL;
	chunk_sort(&lst, &lst_b, index_max);
	// quick_sort(&lst, &lst_b, index_max);
	ft_dlstclear(&lst, free);
	return (0);
}
