/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:50 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/25 16:48:22 by vsenniko         ###   ########.fr       */
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
int		swap(t_list **lst);
int		swap_both(t_list **lst_a, t_list **lst_b);
int		push(t_list **lst_a, t_list **lst_b);
int		rotate(t_list **lst);
int		rotate_both(t_list **lst_a, t_list **lst_b);
int		reverse_rotate(t_list **lst);
int		reverse_rotate_both(t_list **lst_a, t_list **lst_b);
t_list	*create_lst_b(t_list **lst);
#endif