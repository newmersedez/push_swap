/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:02:11 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/13 14:32:07 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	display_error_message(char *message)
{
	ft_putendl_fd(message, 2);
}

void	fail_exit(t_stack **a, t_stack **b)
{
	display_error_message("Error");
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_FAILURE);
}

void	success_exit(t_stack **a, t_stack **b)
{
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_SUCCESS);
}
