/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:02:11 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/10 19:28:37 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fail_exit(t_stack **a, t_stack **b)
{
	ft_putendl("ERROR");
	clear_stacks(a, b);
	exit(EXIT_FAILURE);
}

void	success_exit(t_stack **a, t_stack **b)
{
	clear_stacks(a, b);
	exit(EXIT_SUCCESS);
}
