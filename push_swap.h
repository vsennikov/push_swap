/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:50 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/29 14:30:28 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

void	exit_error(void);

// validation
void	parse_into_lst(int argc, char **argv, t_list **lst);
void	free_validation(char **tmp, t_list **lst);
int		valid_input(char *str);

// sorting
char	*swap_a(t_list **lst);
char	*swap_b(t_list **lst);
char	*swap_both(t_list **lst_a, t_list **lst_b);
char	*push_a(t_list **lst_b, t_list **lst_a);
char	*push_b(t_list **lst_a, t_list **lst_b);
char	*rotate_a(t_list **lst);
char	*rotate_b(t_list **lst);
char	*rotate_both(t_list **lst_a, t_list **lst_b);
char	*reverse_rotate_a(t_list **lst);
char	*reverse_rotate_b(t_list **lst);
char	*reverse_rotate_both(t_list **lst_a, t_list **lst_b);

//algo
void sort_stacks(t_list **lst_a, t_list **lst_b);
// void	sort_stacks_a(t_list **lst_a, t_list **lst_b);
// void	sort_stacks_b(t_list **lst_a, t_list **lst_b);
#endif