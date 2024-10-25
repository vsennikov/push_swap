/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:36:59 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/25 17:30:17 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	free_lsts(t_list **lst_a, t_list **lst_b)
// {
// 	if (lst_a != NULL && *lst_a != NULL)
// 		ft_lstclear(lst_a, free);
// 	if (lst_b != NULL && *lst_b != NULL)
// 		ft_lstclear(lst_a, free);
// 	exit_error();
// }

// t_list	*create_lst_b(t_list **lst)
// {
// 	t_list	*lst_b;
// 	t_list	*lst_a;
// 	t_list	*node;
// 	int		*value;
	
// 	lst_b = NULL;
// 	lst_a = *lst;
// 	value = malloc(sizeof(int));
// 	if (value == NULL)
// 		free_lsts(lst, &lst_b);
// 	*value = 0;
// 	while (lst_a)
// 	{
// 		node = ft_lstnew(value);
// 		if (node == NULL)
// 			free_lsts(lst, &lst_b);
// 		ft_lstadd_back(&lst_b, node);
// 		lst_a = lst_a->next;
// 	}
// 	return (lst_b);
// }
