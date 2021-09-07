/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:36:36 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 15:34:24 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	size_t			size;

	struct s_stack	*next;
}	t_stack;

t_stack	*create(int data);
void	clear(t_stack **stack);
void	print(t_stack *stack);
int		top(t_stack *stack);

void	swap(t_stack **stack);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_a_swap_b(t_stack **a, t_stack **b);

void	push(t_stack **stack, int data);
void	push_a(t_stack **a, t_stack *b);
void	push_b(t_stack **b, t_stack *a);

void	rotate(t_stack **stack);

#endif