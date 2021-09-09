/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:36:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/09 17:44:16 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

t_stack	*stack_create(int data)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->data = data;
	new_stack->index = 0;
	new_stack->next = NULL;
	return (new_stack);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*temp_stack;

	if (!stack || !*stack)
		return ;
	else
	{
		while (*stack)
		{	
			temp_stack = *stack;
			*stack = (*stack)->next;
			free(temp_stack);
		}
		*stack = NULL;
	}
}

void	stack_print(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_putnbr(stack->data);
		ft_putchar('\n');
		stack = stack->next;
	}
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
