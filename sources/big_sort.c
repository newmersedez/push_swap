/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 15:15:31 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


////////////////////////////////////////////////////////////

int	_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top_id;
	while (stack->array[i] != n && i >= 0)
		i--;
	return (i);
}

static int	find_from_top(t_stack *a, int min, int max)
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

static int	find_from_bottom(t_stack *a, int min, int max)
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
	if (index[0] <(*b)->top_id - index[1])
		i = index[0];
	else
		i = index[1];
	balance_rotate_b(b, (*b)->array[i]);
}

////////////////////////////////////////////////////////////


void	sort_chunk(t_stack **a, t_stack **b)
{
	int	top_b;
	int	to_move;
	
	while ((*b)->top_id >= 0)
	{
		move_min_or_max_to_top(b);
		top_b = (*b)->array[(*b)->top_id];
		to_move = find_close_number(*a, top_b);
		if (to_move == top_b && (*a)->top_id >= 0)
			to_move = min(*a);
		balance_rotate_a(a, to_move);
		push_a(a, b);
	}
}

void	move_chunk(t_stack **a, t_stack **b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size)
	{
		move_to_top(a, min, max);
		push_b(a, b);
		size--;
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	int		limit_min;
	int		limit_max;
	int		chunks;
	size_t	step;

	chunks = ((*a)->top_id + 1) / CHUNK_SIZE + 1;
	limit_max = max(*a);
	step = ((*a)->top_id + 1) / chunks;
	while (chunks >= 1)
	{
		if (chunks == 1)
			limit_min = min(*a);
		else
			limit_min = limit_max - step + 1;
		move_chunk(a, b, limit_min, limit_max);
		sort_chunk(a, b);
		limit_max = limit_min - 1;
		chunks--;
	}
	balance_rotate_a(a, min(*a));
}
