/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:50 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/08 12:05:04 by vsenniko         ###   ########.fr       */
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
	int				content;
	int				index;
	struct sd_list	*prev;
	struct sd_list	*next;
}					t_dlist;

t_dlist				*ft_dlstnew(int content, int index);
void				ft_dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist				*ft_dlstlast(t_dlist *lst);
void				ft_dlstadd_back(t_dlist **lst, t_dlist *new);
int					ft_dlstsize(t_dlist *lst);
void				ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void				ft_dlstclear(t_dlist **lst, void (*del)(void *));

// errors
void				exit_error(void);
void				sort_exit(t_dlist **lst);
void				free_exit_validation(char **str, t_dlist **lst, int style);
void				free_double_dem(char **d_arr);
// validation
void				check_style_pass_next(int argc, char **argv, t_dlist **lst);
int					check_if_ordered(t_dlist **lst);
// sorting
char				*swap_a(t_dlist **lst);
char				*swap_b(t_dlist **lst);
char				*push_a(t_dlist **lst_b, t_dlist **lst_a);
char				*push_b(t_dlist **lst_a, t_dlist **lst_b);
char				*rotate_a(t_dlist **lst);
char				*rotate_b(t_dlist **lst);
char				*reverse_rotate_a(t_dlist **lst);
char				*reverse_rotate_b(t_dlist **lst);

// algo
int					pre_sort(t_dlist **lst_a, t_dlist **lst_b);
int					max_index(t_dlist **lst);
int					calculate_better_top(t_dlist **lst, int top_index);
int					calculate_better_bottom(t_dlist **lst, int bottom_index);
int					look_for_closer_index_top(t_dlist **lst, int start_range,
						int chucnk_size);
int					look_for_closer_index_bottom(t_dlist **lst, int start_range,
						int chucnk_size);
void				chunk_sort(t_dlist **lst_a, t_dlist **lst_b, int max_index,
						int chunck_size);
void				sort_three(t_dlist **lst_a);
void				sort_four(t_dlist **lst_a, t_dlist **lst_b);
void				sort_five(t_dlist **lst_a, t_dlist **lst_b);
#endif