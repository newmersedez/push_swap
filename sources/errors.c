/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:02:11 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/10 18:28:40 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	display_message(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}

void	emergency_exit(t_stack **a, t_stack **b)
{
	display_message();
	clear_stacks(a, b);
	exit(EXIT_FAILURE);
}

void	good_exit(t_stack **a, t_stack **b)
{
	clear_stacks(a, b);
	exit(EXIT_FAILURE);
}
