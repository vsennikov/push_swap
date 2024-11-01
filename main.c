/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/01 12:42:24 by vsenniko         ###   ########.fr       */
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
	t_list	*lst;
	t_list	*lst_b;
	
	if (argc < 2)
		return (1);
	lst = NULL;
	lst_b = NULL;
	parse_into_lst(argc, argv, &lst);
	// ft_printf("List before sorting:\n");
	// printlst_int(lst);
	// sort_stacks(&lst, &lst_b);
	printlst_int(lst);
	ft_lstclear(&lst, free);
	return (0);
	// ft_printf("List after sorting:\n");
	// printlst_int(lst);
	// ft_printf("List A before swaping:\n");
	// printlst_int(lst);
	// // lst_b = create_lst_b(&lst);
	// push(&lst, &lst_b);
	// ft_printf("List A after 1 swap:\n");
	// printlst_int(lst);
	// ft_printf("List B after 1 swap:\n");
	// printlst_int(lst_b);
	// push(&lst, &lst_b);
	// ft_printf("List A after 2 swap:\n");
	// printlst_int(lst);
	// ft_printf("List B after 2 swap:\n");
	// printlst_int(lst_b);
	// push(&lst, &lst_b);
	// ft_printf("List A after 3 swap:\n");
	// printlst_int(lst);
	// ft_printf("List B after 3 swap:\n");
	// printlst_int(lst_b);
}
