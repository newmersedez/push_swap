/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:34:52 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 20:19:15 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

void	swap(t_stack **stack)
{
	int	temp_data;
	int	top_id;

	top_id = (*stack)->top_id;
	if (top_id > 0)
	{
		temp_data = (*stack)->array[top_id];
		(*stack)->array[top_id] = (*stack)->array[top_id - 1];
		(*stack)->array[top_id - 1] = temp_data;
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
