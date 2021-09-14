/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:17:07 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 17:31:19 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CHUNK_SIZE_100 30
# define CHUNK_SIZE_500 55
# define ALGORITHM_LIMIT 5

# include "stack_utils.h"
# include "libft.h"

/* Utils */

void	fill_stack_with_args(t_stack **a, t_stack **b, int argc, char *argv[]);
void	set_index_numbers(t_stack **a, t_stack **b);

/* Clear memory and exit */

void	clear_stacks(t_stack **a, t_stack **b);
void	fail_exit(t_stack **a, t_stack **b);
void	success_exit(t_stack **a, t_stack **b);

/* Sorting */

void	sort(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);
void	big_sort(t_stack **a, t_stack **b);

/* Sorting utils */

int		get_index(t_stack *stack, int n);
int		find_close_number(t_stack *a, int n);
int		find_pos_from_top(t_stack *a, int min, int max);
int		find_pos_from_bottom(t_stack *a, int min, int max);
void	move_min_or_max_to_top(t_stack **b);
void	balance_rotate_a(t_stack **a, int n);
void	balance_rotate_b(t_stack **b, int n);
void	move_to_top(t_stack **a, int min, int max);

#endif