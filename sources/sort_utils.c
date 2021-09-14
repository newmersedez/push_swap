/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:21:32 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 15:06:08 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_close_number(t_stack *a, int n)
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

void	balance_rotate_a(t_stack **a, int n)
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

void	balance_rotate_b(t_stack **b, int n)
{
	int	pos;
	int	rotates_count;

	pos = (*b)->top_id;
	while (pos != -1 && (*b)->array[pos] != n)
		pos--;
	if (pos != -1)
	{
		if (pos < (*b)->top_id / 2)
		{
			rotates_count = pos + 1;
			while (rotates_count--)
				reverse_rotate_b(b);
		}
		else
		{
			rotates_count = (*b)->top_id - pos;
			while (rotates_count--)
				rotate_b(b);
		}
	}
}
