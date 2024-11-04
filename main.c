/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 11:44:57 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

// void printlst(t_list *lst)
// {
// 	while (lst)
// 	{
// 		ft_printf("%s,\n", (char *)((lst)->content));
// 		lst = (lst)->next;
// 	}
// 	ft_printf("\n");
// }

// void printlst_int(d_list *lst)
// {
// 	while (lst)
// 	{
// 		ft_printf("%d\n", *(int *)(lst->content));
// 		lst = (lst)->next;
// 	}
// }
void printlst_int_in(d_list *lst)
{
	while (lst)
	{
		ft_printf("value = %d, index = %d\n", lst->content, lst->index);
		lst = (lst)->next;
	}
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
	// printlst_int_in(lst);
	// ft_printf("List before sorting:\n");
	// printlst_int(lst);
	index_max = pre_sort(&lst, &lst_b);
	// printlst_int_in(lst);
	lst_b = NULL;
	// ft_printf("List before sorting:\n");
	// printlst_int_in(lst);
	sort_stacks(&lst, &lst_b, index_max);
	// printlst_int(lst);
	ft_dlstclear(&lst, free);
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
