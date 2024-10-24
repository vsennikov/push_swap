/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/24 18:25:00 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

void printlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s,\n", (char *)((lst)->content));
		lst = (lst)->next;
	}
}

int	main(int argc, char **argv)
{
	t_list *lst_start;
	
	if (argc < 2)
		return (1);
	lst_start = NULL;
	parse_into_lst(argc, argv, &lst_start);
	printlst(lst_start);
}
