/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:35:45 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/12 16:38:22 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if ((*a)->size <= ALGORITHM_LIMIT)
		small_sort(a, b);
	else
		big_sort(a, b);
}
