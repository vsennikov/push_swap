/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:56:28 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/05 15:03:42 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	sort_exit(t_dlist **lst)
{
	ft_dlstclear(lst, free);
	exit_error();
}

void	free_exit_validation(char **str, t_dlist **lst, int style)
{
	int	i;

	i = 0;
	if (lst != NULL && *lst != NULL)
		ft_dlstclear(lst, free);
	if (style)
		exit_error();
	while (str[i])
		free(str[i++]);
	free(str);
	exit_error();
}
