/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:34:52 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/10 21:18:50 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

void	swap(t_stack **stack)
{
	t_stack	*temp_first;
	t_stack	*temp_second;
	t_stack	*temp_third;

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
	}	
}

void	swap_a(t_stack **a)
{
	swap(a);
	ft_putendl("sa");
}

void	swap_b(t_stack **b)
{
	swap(b);
	ft_putendl("sb");
}

void	swap_a_swap_b(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl("ss");
}
