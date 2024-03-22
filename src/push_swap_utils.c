/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:11:03 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:50:15 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_double_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

char	**get_args(int ac, char **av)
{
	char	**args;

	args = malloc(sizeof(*args) * ac);
	if (!args)
		return (NULL);
	args[ac--] = 0;
	while (ac--)
	{
		args[ac] = ft_strdup(av[ac + 1]);
		if (args[ac] == NULL)
			return (NULL);
	}
	return (args);
}

char	**process_args(int ac, char **av)
{
	char	**split;

	if (ac == 1 || (ac == 2 && ft_strlen(av[1]) == 0))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	else if (ac > 2)
		split = get_args(ac, av);
	else if (ac == 2)
		split = ft_split(av[1], ' ');
	if (split == NULL || split[0] == 0)
	{
		if (split[0] == 0)
			free_double_array(split);
		write (2, "Error\n", 6);
		exit (1);
	}
	return (split);
}

void	sort(t_stack_node *a, t_stack_node *b)
{
	if (stack_len(a) == 2)
	{
		sa(&a, 1);
		free_stack(&a);
	}
	else if (stack_len(a) == 3)
		sort_three(&a, 3);
	else
		sort_stacks(&a, &b);
}

