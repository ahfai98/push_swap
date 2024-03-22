/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:58:20 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 13:01:17 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	error_syntax(char *str)
{
	if (*str == '+' || *str == '-')
	{
		if (!(str[1] >= '0' && str[1] <= '9'))
			return (1);
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write (2, "Error\n", 6);
	exit(1);
}

void	free_double_array_and_stack(char **array, t_stack_node **stack)
{
	free_double_array(array);
	free_errors(stack);
}
