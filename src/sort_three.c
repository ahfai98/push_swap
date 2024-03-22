/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:30:15 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:43:11 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack_node **a, int len_a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, 1);
	else if (biggest_node == (*a)->next)
		rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
	if (len_a == 3)
		free_stack(a);
}
