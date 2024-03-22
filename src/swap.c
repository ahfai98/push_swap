/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:30:15 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:44:17 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack_node **stack)
{
	if (*stack == 0 || (*stack)->next == 0)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a, int p)
{
	swap(a);
	if (p)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, int p)
{
	swap(b);
	if (p)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, int p)
{
	swap(a);
	swap(b);
	if (p)
		ft_printf("ss\n");
}
