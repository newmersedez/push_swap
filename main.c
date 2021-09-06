/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:36:38 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/06 20:24:53 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack/stack_utils.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = NULL;
	push(&stack, 3);
	push(&stack, -421);
	push(&stack, 42);
	push(&stack, 12);

	while (stack)
	{
		printf("elem = %d, size %d\n", stack->data, stack->data);
		stack = stack->next;
	}
	clear(&stack);
	return (0);
}
