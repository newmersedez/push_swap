/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:10 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 17:25:25 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_pos_from_top(t_stack *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (pos <= a->top_id)
	{
		if (a->array[pos] >= min && a->array[pos] <= max)
			return (pos);
		pos++;
	}
	return (-1);
}

int	find_pos_from_bottom(t_stack *a, int min, int max)
{
	int	pos;

	pos = a->top_id;
	while (pos >= 0)
	{
		if (a->array[pos] >= min && a->array[pos] <= max)
			return (pos);
		pos--;
	}
	return (-1);
}

void	move_to_top(t_stack **a, int min, int max)
{
	int	i;
	int	pos_top;
	int	pos_bottom;

	pos_top = find_pos_from_top(*a, min, max);
	pos_bottom = find_pos_from_bottom(*a, min, max);
	if (pos_top < (*a)->top_id - pos_bottom)
		i = pos_top;
	else
		i = pos_bottom;
	balance_rotate_a(a, (*a)->array[i]);
}

int	get_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top_id;
	while (i != -1 && stack->array[i] != n)
		i--;
	return (i);
}

void	move_min_or_max_to_top(t_stack **b)
{
	int	i;
	int	pos_top;
	int	pos_bottom;

	pos_top = get_index(*b, min(*b));
	pos_bottom = get_index(*b, max(*b));
	if (pos_top < (*b)->top_id - pos_bottom)
		i = pos_top;
	else
		i = pos_bottom;
	balance_rotate_b(b, (*b)->array[i]);
}
