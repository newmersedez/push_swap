/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/13 13:36:53 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_elements(t_stack **a)
{
	int	top_id;
	int	first;
	int	second;
	int	third;

	top_id = (*a)->top_id;
	first = (*a)->array[top_id];
	second = (*a)->array[top_id - 1];
	third = (*a)->array[top_id - 2];
	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
	else if (first > second && second > third && first > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
}

static int	find_close_number(t_stack *a, int n)
{
	int	i;
	int	number;

	if (a->top_id < 0 || n > max(a))
		return (n);
	i = 0;
	number = max(a);
	while (i < a->top_id + 1)
	{
		if (a->array[i] > n && a->array[i] < number)
			number = a->array[i];
		i++;
	}
	return (number);
}

static void	balance_rotate(t_stack **a, int n)
{
	int	pos;
	int	rotates_count;

	pos = (*a)->top_id;
	while (pos != -1 && (*a)->array[pos] != n)
		pos--;
	if (pos != -1)
	{
		if (pos < (*a)->top_id / 2)
		{
			rotates_count = pos + 1;
			while (rotates_count--)
				reverse_rotate_a(a);
		}
		else
		{
			rotates_count = (*a)->top_id - pos;
			while (rotates_count--)
				rotate_a(a);
		}
	}
}

static void	sort_five_elements(t_stack **a, t_stack **b)
{
	int	pos;
	int	b_top_id;
	int	b_first;

	while ((*a)->top_id != 2)
		push_b(a, b);
	sort_three_elements(a);
	while ((*b)->top_id != -1)
	{
		b_top_id = (*b)->top_id;
		b_first = (*b)->array[b_top_id];
		pos = find_close_number(*a, b_first);
		if (pos == b_first)
			pos = min(*a);
		balance_rotate(a, pos);
		push_a(a, b);
	}
	balance_rotate(a, 0);
}

void	small_sort(t_stack **a, t_stack **b)
{
	if ((*a)->size == 2)
		swap_a(a);
	else if ((*a)->size == 3)
		sort_three_elements(a);
	else
		sort_five_elements(a, b);
}
