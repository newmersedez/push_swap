/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:51:06 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 15:46:33 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b)
		exit(EXIT_FAILURE);
	if (stack_size(*a) < ALGORITHM_LIMIT)
		small_sort(a, b);
	else
		big_sort(a, b);
}
