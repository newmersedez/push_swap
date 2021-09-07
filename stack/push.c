/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:16:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 15:15:34 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	push(t_stack **stack, int data)
{
	t_stack	*new_stack;
	t_stack	*temp_stack;

	if (!stack)
		return ;
	new_stack = create(data);
	if (!new_stack)
		return ;
	if (!*stack)
		*stack = new_stack;
	else
	{
		temp_stack = *stack;
		*stack = new_stack;
		new_stack->next = temp_stack;
		(*stack)->size = temp_stack->size + 1;
	}
}

void	push_a(t_stack **a, t_stack *b)
{
	if (!a || !b)
		return ;
	push(a, top(b));
}

void	push_b(t_stack **b, t_stack *a)
{
	if (!a || !b)
		return ;
	push(b, top(a));
}
