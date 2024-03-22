/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:50:14 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 17:33:05 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_syntax(char *str);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			free_double_array(char **array);
void			free_double_array_and_stack(char **array, t_stack_node **stack);

void			init_stack_a(t_stack_node **a, char **av);

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top, char c);

int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
int				stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

void			sa(t_stack_node **a, int p);
void			sb(t_stack_node **b, int p);
void			ss(t_stack_node **a, t_stack_node **b, int p);
void			ra(t_stack_node **a, int p);
void			rb(t_stack_node **b, int p);
void			rr(t_stack_node **a, t_stack_node **b, int p);
void			rra(t_stack_node **a, int p);
void			rrb(t_stack_node **b, int p);
void			rrr(t_stack_node **a, t_stack_node **b, int p);
void			pa(t_stack_node **a, t_stack_node **b, int p);
void			pb(t_stack_node **b, t_stack_node **a, int p);

void			push_cost_calculations(t_stack_node *a, t_stack_node *b);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			sort_three(t_stack_node **a, int len_a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
char			**process_args(int ac, char **av);
void			sort(t_stack_node *a, t_stack_node *b);

#endif
