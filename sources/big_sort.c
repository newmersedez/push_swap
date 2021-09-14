/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 17:25:16 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_moved_chunk(t_stack **a, t_stack **b)
{
	int	pos;
	int	b_first;

	while ((*b)->top_id >= 0)
	{
		b_first = (*b)->array[(*b)->top_id];
		move_min_or_max_to_top(b);
		pos = find_close_number(*a, b_first);
		if (pos == b_first && (*a)->top_id != -1)
			pos = min(*a);
		balance_rotate_a(a, pos);
		push_a(a, b);
	}
}

static void	move_chunk(t_stack **a, t_stack **b, int min, int max)
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
	int		chunk_size;
	int		count;
	int		offset;
	int		bound_max;
	int		bound_min;

	bound_max = max(*a);
	if ((*a)->size >= 6 && (*a)->size <= 100)
		chunk_size = CHUNK_SIZE_100;
	else
		chunk_size = CHUNK_SIZE_500;
	count = (*a)->size / chunk_size + 1;
	offset = (*a)->size / count;
	while (count)
	{
		if (count == 1)
			bound_min = min(*a);
		else
			bound_min = bound_max - offset + 1;
		move_chunk(a, b, bound_min, bound_max);
		sort_moved_chunk(a, b);
		bound_max = bound_min - 1;
		count--;
	}
	balance_rotate_a(a, 0);
}
