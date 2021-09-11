/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:57:20 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 19:18:54 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	three_elements_sort(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && second < third && first < third)
		swap_a(stack);
	else if (first > second && second < third && first > third)
		rotate_a(stack);
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack);
	else if (first > second && second > third && first > third)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (first < second && second > third && first < third)
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

static void	smart_push_a(t_stack **a, t_stack **b)
{
	t_stack	*b_first;
	t_stack	*a_first;
	t_stack	*a_last;

	b_first = *b;
	a_first = *a;
	a_last = *a;
	while (a_last->next)
		a_last = a_last->next;
	if (b_first->data < a_first->data && b_first->data < a_last->data)
		exec_command(PA, a, b);
	else if (b_first->data > a_first->data && b_first->data > a_last->data)
	{
		exec_command(PA, a, b);	
		exec_command(RA, a, b);	
	}
	else if (b_first->data > a_first->data && b_first->data < a_last->data)
	{
		exec_command(PA, a, b);
		exec_command(RRA, a, b);
		exec_command_n(RA, a, b, 2);
	}
}

static void	five_elements_sort(t_stack **a, t_stack **b)
{
	size_t	n;
	
	n = ALGORITHM_LIMIT - stack_size(*a);
	exec_command_n(PB, a, b, n);
	three_elements_sort(a);
	smart_push_a(a, b);
}

void	small_sort(t_stack **a, t_stack **b)
{
	size_t	size;

	size = stack_size(*a);
	if (size == 2)
		exec_command(SA, a, b);
	else if (size == 3)
		three_elements_sort(a);
	else
		five_elements_sort(a, b);
}
