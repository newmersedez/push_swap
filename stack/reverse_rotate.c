/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:34:54 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 21:00:42 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

void	reverse_rotate(t_stack **stack)
{
	int	i;
	int	pos;
	int	temp_data;

	pos = (*stack)->top_id;
	if (pos > 0)
	{
		i = 0;
		temp_data = (*stack)->array[0];
		while (i < pos)
		{
			(*stack)->array[i] = (*stack)->array[i + 1];
			i++;
		}
		(*stack)->array[pos] = temp_data;
	}
}

void	reverse_rotate_a(t_stack **a)
{
	if ((*a)->top_id > 0)
	{	
		reverse_rotate(a);
		ft_putendl("rra");
	}
}

void	reverse_rotate_b(t_stack **b)
{
	if ((*b)->top_id > 0)
	{	
		reverse_rotate(b);
		ft_putendl("rrb");
	}
}

void	reverse_rotate_a_and_reverse_rotate_b(t_stack **a, t_stack **b)
{
	if ((*a)->top_id > 0 || (*b)->top_id > 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_putendl("rrr");
	}
}
