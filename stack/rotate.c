/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:17:01 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/06 20:43:38 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp_stack;
	t_stack	*new_stack;

	if (!stack || !*stack)
		return ;
	if (!(*stack)->next)
		return ;
	else
	{
		while (*stack)
		{
			ft_putnbr((*stack)->data);
			ft_putchar('\n');
			*stack = (*stack)->next;
		}
		*stack = new_stack;
	}
}
