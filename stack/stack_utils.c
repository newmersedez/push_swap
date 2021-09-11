/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:53:05 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 19:46:57 by lorphan          ###   ########.fr       */
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
