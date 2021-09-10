/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:34:53 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/10 18:36:53 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

void	push(t_stack **stack, int data)
{
	t_stack	*new_stack;
	t_stack	*temp_stack;

	if (!stack)
		return ;
	new_stack = stack_create(data);
	if (!new_stack)
		return ;
	if (!*stack)
		*stack = new_stack;
	else
	{
		temp_stack = *stack;
		*stack = new_stack;
		new_stack->next = temp_stack;
	}
}

void	push_a(t_stack **a, t_stack *b)
{
	if (!a || !b)
		return ;
	push(a, b->data);
}

void	push_b(t_stack **b, t_stack *a)
{
	if (!a || !b)
		return ;
	push(b, a->data);
}
