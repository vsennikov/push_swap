/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:12:47 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/01 16:35:12 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_and_add_to_lst(d_list **lst, d_list *node)
{
	d_list	*current;

	if (*lst == NULL)
	{
		*lst = node;
		return (1);
	}
	current = *lst;
	while (current->next != NULL)
	{
		if (*(int *)node->content == *(int *)(current->content))
			return (free(node), 0);
		current = current->next;
	}
	if (current->next == NULL)
	{
		if (*(int *)node->content == *(int *)(current->content))
			return (free(node), 0);
	}
	current->next = node;
	// ft_printf("Put into the list value: %d\n", *(int *)current->next->content);
	return (1);
}

static int	convert_and_check(d_list **lst, d_list *node, int real_len)
{
	int		*tmp;

	if (lst == NULL)
		return (0);
	tmp = malloc(sizeof(int));
	if (tmp == NULL)
		return (0);
	if (real_len >= 10 && real_len <= 11)
	{
		if (ft_atoi((char *)node->content) > 2147483647 ||
		 ft_atoi((char *)node->content) < -2147483648)
			return (free(tmp), 0);
	}
	else if (real_len > 11)
		return (free(tmp), 0);
	*tmp = ft_atoi((char *)node->content);
	free(node->content);
	node->content = tmp;
	return (check_and_add_to_lst(lst, node));
}

int	valid_input(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		len++;
		i++;
	}
	if (str[i])
		return (0);
	if (len == 0)
		return (1);
	return (len);
}

// void print_tmp(char **tmp)
// {
// 	int	i;

// 	ft_printf("Printing tmp after split:\n");
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		ft_printf("%s\n", tmp[i]);
// 		i++;
// 	}
// 	ft_printf("Finished\n\n");
// }

static void	valid_and_put(char **tmp, int j, d_list **lst)
{
	d_list	*node;
	int		real_len;

	while (tmp[j])
	{
		// ft_printf("tmp[%d] = %s\n", j, tmp[j]);
		real_len = valid_input(tmp[j]);
		if (real_len == 0)
			free_validation(tmp, lst);
		node = ft_dlstnew(tmp[j++]);
		if (node == NULL)
			free_validation(tmp, lst);
		if (!convert_and_check(lst, node, real_len))
		{
			// free(node);
			free_validation(tmp, lst);
		}
	}
}

void	parse_into_lst(int argc, char **argv, d_list **lst)
{
	int		i;
	int		j;
	char	**tmp;

	*lst = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (tmp == NULL)
			free_validation(tmp, lst);
		j = 0;
		valid_and_put(tmp, j, lst);
		free(tmp);
		// ft_printf("i = %d\n", i);
		i++;
	}	
}
