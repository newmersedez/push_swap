/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:20:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 16:01:46 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	swap(t_stack **stack)
{
	t_stack	*temp_first;
	t_stack	*temp_second;
	t_stack	*temp_third;
	size_t	temp_size;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	else
	{
		temp_first = *stack;
		temp_second = (*stack)->next;
		temp_third = (*stack)->next->next;
		temp_second->next = temp_first;
		temp_first->next = temp_third;
		*stack = temp_second;
		temp_size = (*stack)->data;
		(*stack)->size = (*stack)->next->size;
		(*stack)->next->size = temp_size;
	}	
}

void	swap_a(t_stack **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	swap_a_swap_b(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
