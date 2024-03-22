/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:30:15 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:40:18 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, int p)
{
	rev_rotate(a);
	if (p)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, int p)
{
	rev_rotate(b);
	if (p)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int p)
{
	rev_rotate(a);
	rev_rotate(b);
	if (p)
		ft_printf("rrr\n");
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, 1);
	current_index(*a);
	current_index(*b);
}
