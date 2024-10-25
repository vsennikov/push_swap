/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:33 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/25 14:27:36 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_validation(char **tmp, t_list **lst)
{
	int	j;

	j = 0;
	free(tmp);
	ft_lstclear(lst, free);
	exit_error();
}

static int	check_if_greater_than_int_max_possibly(char *str, int *i, int sign,
		char *int_max)
{
	int	j;
	int	bigger;

	j = 0;
	bigger = 0;
	while (j < 9 && str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] > int_max[j])
			bigger = 1;
		j++;
		(*i)++;
	}
	if (j == 9)
	{
		if ((sign < 0 && str[*i] > '8') || (sign > 0 && str[*i] > '7'))
			return (0);
		(*i)++;
	}
	return (1);
}

int	valid_input(char *str)
{
	int	i;
	int	j;
	int	bigger;
	int	sign;

	j = 0;
	i = 0;
	bigger = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (!check_if_greater_than_int_max_possibly(str, &i, sign, "214748364"))
		return (0);
	if (str[i])
		return (0);
	return (1);
}
