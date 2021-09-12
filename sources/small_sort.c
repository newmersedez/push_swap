/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/12 17:25:14 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	(void)a;
	(void)b;
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
