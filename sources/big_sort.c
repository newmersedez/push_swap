/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:38:31 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 13:33:42 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	// size_t	step;
	// size_t	chunks;
	// int		limit_min;
	// int		limit_max;

	// chunks = get_chunks(a);
	// limit_max = max(a);
	// step = ((*a)->top_id + 1) / chunks;
	// while (chunks >= 1)
	// {
	// 	if (chunks == 1)
	// 		limit_min = min(a);
	// 	else
	// 		limit_min = limit_max - step + 1;
	// 	move_chunk(a, b, limit_min, limit_max);
	// 	sort_chunk(a, b);
	// 	limit_max = limit_min - 1;
	// 	chunks--;
	// }
	// smart_rotate_a(a, min(a));
	(void)a;
	(void)b;
}
