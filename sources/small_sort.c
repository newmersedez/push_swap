/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/12 20:33:26 by lorphan          ###   ########.fr       */
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

static int	find_close_position(t_stack *a, int n)
{
	int i;

	i = 0;
	while (i != a->top_id)
	{
		if (n < a->array[i])
			i++;
		else
			break ;
	}
	return (i);
}

static void	smart_insert_to_a(t_stack **a, t_stack **b)
{
	int	a_first;
	int	a_last;
	int	b_first;
	int	pos;
	int	i;

	a_first = (*a)->array[(*a)->top_id];
	a_last = (*a)->array[0];
	b_first = (*b)->array[(*b)->top_id];
	if (b_first < a_first && b_first < a_last)
	{
		push_a(a, b);
	}
	else if (b_first > a_first && b_first > a_last)
	{
		push_a(a, b);
		rotate_a(a);
	}
	else if (b_first > a_first && b_first < a_last)
	{
		pos = find_close_position(a, b_first);
		if (pos >= (*a)->size / 2)
		{
			i = 0;
			while (i < pos)
			{
				reverse_rotate_a(a);		
				i++;
			}
			// push_a(a, b);
			// swap_a(a);
			// i = 0;
			// while (i < pos)
			// {
			// 	rotate_a(a);		
			// 	i++;
			// }
		}
		else
		{
			i = 0;
			while (i < pos)
			{
				reverse_rotate_a(a);		
				i++;
			}
		}
	}
}

static void	sort_five_elements(t_stack **a, t_stack **b)
{
	while ((*a)->top_id != 2)
		push_b(a, b);
	sort_three_elements(a);
	while ((*b)->top_id != -1)
		smart_insert_to_a(a, b);
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
