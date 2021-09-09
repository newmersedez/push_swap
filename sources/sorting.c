/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:27:32 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/09 18:53:21 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_sorted(t_stack *stack)
{
	t_stack	*previous_stack;
	t_stack	*current_stack;

	if (!stack)
		return (1);
	previous_stack = NULL;
	current_stack = stack;
	while (current_stack->next)
	{
		previous_stack = current_stack;
		current_stack = current_stack->next;
		if (previous_stack->data > current_stack->data)
			return (0);
	}
	return (1);
}

void	sorting_algorythm(t_stack **a, t_stack **b)
{
	size_t	size;

	if (!a || !*a || !b)
		return ;
	if (is_sorted(*a))
		return ;
	else
	{
		size = stack_size(*a);
		if (size <= 5)
			sort_small_stack(a, b);
		else
			sort_big_stack(a, b);
	}
	if (!is_sorted(*a))
		handle_error(a);
}
