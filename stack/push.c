/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:34:53 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 20:13:07 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

void	push(t_stack **stack, int data)
{
	int	insert_id;

	insert_id = ++(*stack)->top_id;
	(*stack)->array[insert_id] = data;
}

void	push_a(t_stack **a, t_stack **b)
{
	int	move_id;
	int	move_data;

	move_id = (*b)->top_id;
	if (move_id != -1)
	{
		move_data = (*b)->array[move_id];
		push(a, move_data);
		pop(b);
		ft_putendl("pa");
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	int	move_id;
	int	move_data;

	move_id = (*a)->top_id;
	if (move_id != -1)
	{
		move_data = (*a)->array[move_id];
		push(b, move_data);
		pop(a);
		ft_putendl("pb");
	}
}
