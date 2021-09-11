/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:57:20 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 16:05:39 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_elements_sort(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
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

void	five_elements_sort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}

void	small_sort(t_stack **a, t_stack **b)
{
	size_t	size;

	size = stack_size(*a);
	if (size == 2)
		swap_a(a);
	else if (size == 3)
		three_elements_sort(a);
	else
		five_elements_sort(a, b);
}
