/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:33 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 11:29:09 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_exit_validation(char **str, d_list **lst, int style)
{
	int	i;

	i = 0;
	if (lst != NULL && *lst !=NULL)
		ft_dlstclear(lst, free);
	if (style)
		exit_error();
	while (str[i])
		free(str[i++]);
	free(str);
	exit_error();
}

