/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:53:05 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/12 19:25:30 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

t_stack	*stack_create(size_t size)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->array = (int *)malloc(size * sizeof(int));
	if (!new_stack->array)
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->size = size;
	new_stack->top_id = -1;
	return (new_stack);
}

void	stack_clear(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->array)
		free((*stack)->array);
	free(*stack);
}

void	pop(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->top_id != -1)
		(*stack)->top_id--;
}

int	min(t_stack *stack)
{
	size_t	i;
	int		min;

	if (stack->top_id == 0)
		return (stack->array[0]);
	else
	{
		i = 0;
		min = stack->array[0];
		while (i <= (size_t)stack->top_id)
		{
			if (stack->array[i] < min)
				min = stack->array[i];
			i++;
		}
	}
	return (min);
}

int	max(t_stack *stack)
{
	size_t	i;
	int		max;

	if (stack->top_id == 0)
		return (stack->array[0]);
	else
	{
		i = 0;
		max = stack->array[0];
		while (i <= (size_t)stack->top_id)
		{
			if (stack->array[i] > max)
				max = stack->array[i];
			i++;
		}
	}
	return (max);
}
