/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:34:54 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 20:48:17 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

void	rotate(t_stack **stack)
{
	int	pos;
	int	temp_data;

	pos = (*stack)->top_id + 1;
	temp_data = (*stack)->array[pos - 1];
	while (pos)
	{
		(*stack)->array[pos] = (*stack)->array[pos - 1];
		pos--;
	}
	(*stack)->array[0] = temp_data;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_putendl("ra");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_putendl("rb");
}

void	rotate_a_and_rotate_b(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl("rr");
}
