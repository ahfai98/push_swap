/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:50:46 by jyap              #+#    #+#             */
/*   Updated: 2024/03/20 15:08:34 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*void	push_cost_calculations(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}*/

static void	push_cost_above_median(t_stack_node *a, t_stack_node *b, int len_b)
{
	a->push_cost = a->index;
	if (a->target_node->index - a->push_cost <= (len_b / 2))
	{
		if (a->target_node->index - a->push_cost > 0)
			a->push_cost += a->target_node->index - a->push_cost;
	}
	else
		a->push_cost += len_b - a->target_node->index;
}

static void	push_cost_below_median(t_stack_node *a, t_stack_node *b,
	int len_a, int len_b)
{
	a->push_cost = len_a - a->index;
	if (a->target_node->index + a->push_cost > (len_b / 2))
	{
		if (a->target_node->index + a->push_cost <= len_b - 1)
			a->push_cost += len_b
				- a->target_node->index - a->push_cost;
	}
	else
		a->push_cost += a->target_node->index;
}

void	push_cost_calculations(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
			push_cost_above_median(a, b, len_b);
		else
			push_cost_below_median(a, b, len_a, len_b);
		a = a->next;
	}
}
