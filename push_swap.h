/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:50 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/02 12:55:46 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// double list struct & funcs
typedef struct sd_list
{
	void			*content;
	int				index;
	struct sd_list	*prev;
	struct sd_list	*next;
}					d_list;

d_list				*ft_dlstnew(void *content);
void				ft_dlstadd_front(d_list **lst, d_list *new);
d_list				*ft_dlstlast(d_list *lst);
void				ft_dlstadd_back(d_list **lst, d_list *new);
int					ft_dlstsize(d_list *lst);
void				ft_dlstdelone(d_list *lst, void (*del)(void *));
void				ft_dlstclear(d_list **lst, void (*del)(void *));

void				exit_error(void);

// validation
void				parse_into_lst(int argc, char **argv, d_list **lst);
void				free_validation(char **tmp, d_list **lst);
int					valid_input(char *str);

// sorting
char				*swap_a(d_list **lst);
char				*swap_b(d_list **lst);
char				*swap_both(d_list **lst_a, d_list **lst_b);
char				*push_a(d_list **lst_b, d_list **lst_a);
char				*push_b(d_list **lst_a, d_list **lst_b);
char				*rotate_a(d_list **lst);
char				*rotate_b(d_list **lst);
char				*rotate_both(d_list **lst_a, d_list **lst_b);
char				*reverse_rotate_a(d_list **lst);
char				*reverse_rotate_b(d_list **lst);
char				*reverse_rotate_both(d_list **lst_a, d_list **lst_b);

// algo
void				sort_stacks(d_list **lst_a, d_list **lst_b);
void				pre_sort(d_list **lst_a, d_list **lst_b);
int					on_right_pos_a(d_list **lst);
int					on_right_pos_b(d_list **lst);

#endif