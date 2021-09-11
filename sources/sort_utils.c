/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:50:27 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 18:28:00 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_command(char *operation, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(operation, PA))
		push_a(a, b);
	else if (!ft_strcmp(operation, PB))
		push_b(a, b);
	else if (!ft_strcmp(operation, SA))
		swap_a(a);
	else if (!ft_strcmp(operation, SB))
		swap_b(b);
	else if (!ft_strcmp(operation, RA))
		rotate_a(a);
	else if (!ft_strcmp(operation, RB))
		rotate_b(b);
	else if (!ft_strcmp(operation, RRA))
		reverse_rotate_a(a);
	else if (!ft_strcmp(operation, RRB))
		reverse_rotate_b(b);
}

void	exec_command_n(char *operation, t_stack **a, t_stack **b, size_t n)
{
	if (!n)
		return ;
	while (n)
	{
		exec_command(operation, a, b);
		n--;
	}
}