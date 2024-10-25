/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/25 13:49:03 by vsenniko         ###   ########.fr       */
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
	ft_printf("\n");
}

void printlst_int(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", *(int *)(lst->content));
		lst = (lst)->next;
	}
}

int	main(int argc, char **argv)
{
	t_list *lst;
	
	if (argc < 2)
		return (1);
	lst = NULL;
	parse_into_lst(argc, argv, &lst);
	// printlst(lst);
	// convert_into_int(&lst);
	printlst_int(lst);
	ft_lstclear(&lst, free);
}
