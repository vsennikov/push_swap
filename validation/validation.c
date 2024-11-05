/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:21:43 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/04 13:25:18 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

static int	calculate_real_len(char *str)
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

static int add_to_dlst(char *str, d_list **lst, int len, int style, char **args)
{
	d_list *node;

	if (len >= 10 && len <= 11)
	{
		if (ft_atoi(str) > 2147483647 ||
		 ft_atoi(str) < -2147483648)
			return (0);
	}
	else if (len > 11)
		return (0);
	node = ft_dlstnew(ft_atoi(str), 0);
	if (node == NULL)
		free_exit_validation(args, lst, style);
	if (*lst == NULL)
	{
		*lst = node;
		if (!style)
			free(str);
		return (1);
	}
	if (!style)
		free(str);
	ft_dlstadd_back(lst, node);
	return (1);
}

static int	check_for_double(d_list **lst)
{
	d_list	*current;
	d_list	*next;
	int		element;

	current = *lst;
	while (current)
	{
		next = current->next;
		element = current->content;
		while (next)
		{
			if (element == next->content)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

static void validation_parsing_checking(char **args, int style, d_list **lst)
{
	int	i;
	int	len;

	i = 0;
	if (style)
		i = 1;
	while (args[i])
	{
		len = calculate_real_len(args[i]);
		if (!len)
			free_exit_validation(args, lst, style);
		if (!add_to_dlst(args[i], lst, len, style, args))
			free_exit_validation(args, lst, style);
		i++;
	}
	if (!style)
		free(args);
	if (check_for_double(lst))
		free_exit_validation(args, lst, style);
}

void	check_style_pass_next(int argc, char **argv, d_list **lst)
{
	char	**args;
	int		style;

	args = NULL;
	style = 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL)
			exit_error();
		style = 0;
	}
	else
		args = argv;
	validation_parsing_checking(args, style, lst);
} 