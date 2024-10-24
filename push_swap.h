/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:50 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/24 17:50:34 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include "libft.h"

void	parse_into_lst(int argc, char **argv, t_list **lst);
void	exit_error();

#endif