/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:17:01 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 17:39:44 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp_stack;
	t_stack	*stack_first;
	t_stack	*stack_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp_stack = *stack;
	stack_first = (*stack)->next;
	stack_last = *stack;
	while (stack_last->next)
		stack_last = stack_last->next;
	temp_stack->next = NULL;
	stack_last->next = temp_stack;
	*stack = stack_first;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rotate_a_and_rotate_b(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
