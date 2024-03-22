/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:16:09 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:17:45 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split;
	int				i;

	a = NULL;
	b = NULL;
	i = -1;
	split = process_args(ac, av);
	init_stack_a(&a, split);
	if (!stack_sorted(a))
		sort(a, b);
	else
		free_stack(&a);
	free_double_array(split);
	return (0);
}