/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:06:51 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:46:17 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_check_error(t_stack_node **a, t_stack_node **b, char *line)
{
	write(2, "Error\n", 6);
	free(line);
	free_stack(a);
	free_stack(b);
	exit (1);
}

void	ft_check_sub(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[2] == 'a')
		rra(a, 0);
	else if (line[2] == 'b')
		rrb(b, 0);
	else if (line[2] == 'r')
		rrr(a, b, 0);
}

char	*ft_check(t_stack_node **a, t_stack_node **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a, 0);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b, 0);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b, 0);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(b, a, 0);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b, 0);
	else
		ft_check_error(a, b, line);
	return (get_next_line(0));
}

void	ft_checker_sub(t_stack_node **a, t_stack_node **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write (1, "KO\n", 3);
	else if (!stack_sorted(*a))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	free(line);
}

int	main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;
	char		*line;
	char		**split;

	b = NULL;
	if (ac == 1)
		exit (1);
	split = process_args(ac, av);
	init_stack_a(&a, split);
	free_double_array(split);
	line = get_next_line(0);
	if (!line && !stack_sorted(a))
		write(1, "KO\n", 3);
	else if (!line && stack_sorted(a))
		write(1, "OK\n", 3);
	else
		ft_checker_sub(&a, &b, line);
	free_stack(&a);
	free_stack(&b);
	return (0);
}