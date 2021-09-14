/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:10 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 16:39:44 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top_id;
	while (stack->array[i] != n && i != -1)
		i--;
	return (i);
}

int	find_from_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i <= a->top_id)
	{
		if (a->array[i] >= min && a->array[i] <= max)
			return (i);
		i++;
	}
	return (-1);
}

int	find_from_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top_id;
	while (i >= 0)
	{
		if (a->array[i] >= min && a->array[i] <= max)
			return (i);
		i--;
	}
	return (-1);
}

void	move_to_top(t_stack **a, int min, int max)
{
	int	i;
	int	index[2];

	index[0] = find_from_top(*a, min, max);
	index[1] = find_from_bottom(*a, min, max);
	if (index[0] < (*a)->top_id - index[1])
		i = index[0];
	else
		i = index[1];
	balance_rotate_a(a, (*a)->array[i]);
}

void	move_min_or_max_to_top(t_stack **b)
{
	int	i;
	int	index[2];

	index[0] = _index(*b, min(*b));
	index[1] = _index(*b, max(*b));
	if (index[0] < (*b)->top_id - index[1])
		i = index[0];
	else
		i = index[1];
	balance_rotate_b(b, (*b)->array[i]);
}
