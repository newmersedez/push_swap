/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 16:39:32 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_moved_chunk(t_stack **a, t_stack **b)
{
	int	pos;
	int	b_first;

	while ((*b)->top_id >= 0)
	{
		move_min_or_max_to_top(b);
		b_first = (*b)->array[(*b)->top_id];
		pos = find_close_number(*a, b_first);
		if (pos == b_first && (*a)->top_id != -1)
			pos = min(*a);
		balance_rotate_a(a, pos);
		push_a(a, b);
	}
}

static void	move_chunk_in_position(t_stack **a, t_stack **b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size--)
	{
		move_to_top(a, min, max);
		push_b(a, b);
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	int		offset;
	int		count;
	int		bound_max;
	int		bound_min;

	count = ((*a)->size) / CHUNK_SIZE + 1;
	bound_max = max(*a);
	offset = ((*a)->top_id + 1) / count;
	while (count)
	{
		if (count == 1)
			bound_min = min(*a);
		else
			bound_min = bound_max - offset + 1;
		move_chunk_in_position(a, b, bound_min, bound_max);
		sort_moved_chunk(a, b);
		bound_max = bound_min - 1;
		count--;
	}
	balance_rotate_a(a, 0);
}
