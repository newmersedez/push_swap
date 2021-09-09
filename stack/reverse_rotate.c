/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:16:58 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/09 18:46:46 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*stack_first;
	t_stack	*temp_stack;
	t_stack	*stack_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	stack_first = *stack;
	temp_stack = *stack;
	while (temp_stack->next->next)
		temp_stack = temp_stack->next;
	stack_last = temp_stack->next;
	temp_stack->next = NULL;
	stack_last->next = stack_first;
	*stack = stack_last;
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	reverse_rotate_a_and_reverse_rotate_b(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr("rrr\n");
}
