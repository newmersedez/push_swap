/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/12 18:34:01 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

////////////////////////////////////////////////////////////////////////////////////////

static void	exec_command(char *operation, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(operation, PA))
		push_a(a, b);
	else if (!ft_strcmp(operation, PB))
		push_b(a, b);
	else if (!ft_strcmp(operation, SA))
		swap_a(a);
	else if (!ft_strcmp(operation, SB))
		swap_b(b);
	else if (!ft_strcmp(operation, RA))
		rotate_a(a);
	else if (!ft_strcmp(operation, RB))
		rotate_b(b);
	else if (!ft_strcmp(operation, RRA))
		reverse_rotate_a(a);
	else if (!ft_strcmp(operation, RRB))
		reverse_rotate_b(b);
}

static void	exec_command_n_times(char *operation, t_stack **a, t_stack **b, int n)
{
	if (n <= 0)
		return ;
	exec_command(operation, a, b);
	exec_command_n_times(operation, a, b, n - 1);
}

static int	closest_above(t_stack **a, int n)
{
	int	k;
	int	i;

	if ((*a)->top_id < 0 || n > max(*a))
		return (n);
	i = 0;
	k = max(*a);
	while (i <= (*a)->top_id)
	{
		if ((*a)->array[i] > n && (*a)->array[i] < k)
			k = (*a)->array[i];
		i++;
	}
	return (k);
}

void	smart_rotate_a(t_stack **a, int n)
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

static void	put_top_in_position(t_stack **a, t_stack **b)
{
	int	top_b;
	int	to_move;

	top_b = (*b)->array[(*b)->top_id];
	to_move = closest_above(a, top_b);
	if (to_move == top_b)
		to_move = min(*a);
	smart_rotate_a(a, to_move);
	exec_command(PA, a, b);
}

////////////////////////////////////////////////////////////////////////////////////////

void	sort_three_elements(t_stack **a)
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

void	sort_five_elements(t_stack **a, t_stack **b)
{
	exec_command_n_times(PB, a, b, (size_t)(*a)->top_id - 2);
	sort_three_elements(a);
	while ((*b)->top_id >= 0)
		put_top_in_position(a, b);
	smart_rotate_a(a, 0);
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
