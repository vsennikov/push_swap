/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:39 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/25 17:33:04 by vsenniko         ###   ########.fr       */
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
	// lst_b = create_lst_b(&lst);
	ft_printf("List B: \n");
	printlst_int(lst_b);
	ft_printf("Before swap: \n");
	printlst_int(lst);
	ft_printf("After swap:\n");
	swap(&lst);		
	printlst_int(lst);
	ft_printf("After push:\n");
	push(&lst, &lst_b);
	ft_printf("List A: \n");
	printlst_int(lst);
	ft_printf("List B: \n");
	printlst_int(lst_b);
	ft_printf("After rotate:\n");
	rotate(&lst);
	printlst_int(lst);
	ft_printf("After reverse rotate:\n");
	reverse_rotate(&lst);
	printlst_int(lst);

	ft_printf("After push back to A:\n");
	push(&lst_b, &lst);
	ft_printf("List A: \n");
	printlst_int(lst);
	ft_printf("List B:\n");
	printlst_int(lst_b);
	// ft_lstclear(&lst, free);
}
