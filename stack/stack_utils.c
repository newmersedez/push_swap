/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:53:05 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/10 17:54:44 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"

t_stack	*stack_create(int data)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->data = data;
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
