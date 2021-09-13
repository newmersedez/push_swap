/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/13 13:13:40 by lorphan          ###   ########.fr       */
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
	while (i <= a->top_id)
	{
		if (a->array[i] > n && a->array[i] < number)
			number = a->array[i];
		i++;
	}
	return (number);
}

static void	balance_rotate(t_stack **a, int n)
{
	int	find;

	find = (*a)->top_id;
	while (find >= 0 && (*a)->array[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < (*a)->top_id / 2)
		exec_command_n_times(RRA, a, NULL, find + 1);
	else
		exec_command_n_times(RA, a, NULL, (*a)->top_id - find);
}

static void	insert_to_a(t_stack **a, t_stack **b)
{
	int	top_b;
	int	to_move;

	top_b = (*b)->array[(*b)->top_id];
	to_move = find_close_number(*a, top_b);
	if (to_move == top_b)
		to_move = min(*a);
	balance_rotate(a, to_move);
	push_a(a, b);
}

static void	sort_five_elements(t_stack **a, t_stack **b)
{
	while ((*a)->top_id != 2)
		push_b(a, b);
	sort_three_elements(a);
	while ((*b)->top_id != -1)
		insert_to_a(a, b);
	balance_rotate(a, min(*a));
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
