/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:53:02 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 18:08:49 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_create(int data);
void	stack_clear(t_stack **stack);
size_t	stack_size(t_stack *stack);
void	pop(t_stack **stack);

void	swap(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_a_swap_b(t_stack **a, t_stack **b);

void	push(t_stack **stack, int data);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);

void	rotate(t_stack **stack);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_a_and_rotate_b(t_stack **a, t_stack **b);

void	reverse_rotate(t_stack **stack);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_a_and_reverse_rotate_b(t_stack **a, t_stack **b);

#endif