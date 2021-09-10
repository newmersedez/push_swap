/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:17:07 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/10 21:20:48 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CHUNK_CONSTANT 50
# define ALGORITHM_LIMIT 5

# include "stack_utils.h"
# include "libft.h"

void	fill_stack_with_args(t_stack **a, int argc, char *argv[]);
void	clear_stacks(t_stack **a, t_stack **b);
void	fail_exit(t_stack **a, t_stack **b);
void	success_exit(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);
void	big_sort(t_stack **a, t_stack **b);

#endif