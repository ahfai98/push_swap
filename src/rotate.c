/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:30:15 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:35:24 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, int p)
{
	rotate(a);
	if (p)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, int p)
{
	rotate(b);
	if (p)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, int p)
{
	rotate(a);
	rotate(b);
	if (p)
		ft_printf("rr\n");
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, 1);
	current_index(*a);
	current_index(*b);
}
