/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:17:01 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 16:10:41 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	rotate(t_stack **stack)
{ 
	t_stack	*temp_stack;
	t_stack	*rotated_stack;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	rotated_stack = NULL;
	while (*stack)
	{
		temp_stack = *stack;
		*stack = (*stack)->next;
		push(&rotated_stack, temp_stack->data);
		free(temp_stack);
	}
	*stack = rotated_stack;
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