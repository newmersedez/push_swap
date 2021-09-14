/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:17:07 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 15:24:39 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CHUNK_SIZE 50
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

int		find_close_number(t_stack *a, int n);
void	balance_rotate_a(t_stack **a, int n);
void	balance_rotate_b(t_stack **b, int n);

#endif