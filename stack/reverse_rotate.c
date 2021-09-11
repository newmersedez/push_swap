/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:34:54 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 20:48:42 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

void	reverse_rotate(t_stack **stack)
{
	int	pos;
	int	temp_data;

	pos = (*stack)->top_id;
	if (pos > 0)
	{
		temp_data = (*stack)->array[pos];
		while (pos)
		{
			(*stack)->array[pos + 1] = (*stack)->array[pos];
			pos--;
		}
		(*stack)->array[0] = temp_data;
	}
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	ft_putendl("rra");
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	ft_putendl("rrb");
}

void	reverse_rotate_a_and_reverse_rotate_b(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl("rrr");
}
