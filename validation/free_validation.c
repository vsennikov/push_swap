/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:33 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/01 16:35:36 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_validation(char **tmp, d_list **lst)
{
	int	j;

	j = 0;
	free(tmp);
	ft_dlstclear(lst, free);
	exit_error();
}


