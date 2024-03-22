/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:14:40 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:43:34 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n, char **av)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		free_double_array_and_stack(av, stack);
	node = malloc(sizeof(t_stack_node));
	if (!node)
		free_double_array_and_stack(av, stack);
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_double_array_and_stack(av, a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_double_array_and_stack(av, a);
		if (error_duplicate(*a, (int)n))
			free_double_array_and_stack(av, a);
		append_node(a, (int)n, av);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
