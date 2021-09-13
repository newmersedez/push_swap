/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:28:55 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/13 12:37:16 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insertion_sort(int *array, size_t size)
{
	int				i;
	unsigned int	j;
	int				key;

	j = 1;
	while (j < size)
	{
		i = j - 1;
		key = array[j++];
		while (i >= 0 && array[i + 1] < array[i])
		{
			array[i + 1] = array[i];
			array[i--] = key;
		}
	}
}

static int	*sorted_array_copy(t_stack **stack)
{
	int		*copy;
	size_t	size;

	size = (*stack)->top_id + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, (*stack)->array, size * sizeof(*copy));
	insertion_sort(copy, size);
	return (copy);
}

void	set_index_numbers(t_stack **stack)
{
	int		*copy;
	int		i;
	size_t	pos;
	int		*array;

	i = 0;
	array = ft_calloc((*stack)->top_id + 1, sizeof(*array));
	copy = sorted_array_copy(stack);
	while (i <= (*stack)->top_id)
	{
		pos = 0;
		while (copy[pos] != (*stack)->array[i])
			pos++;
		array[i++] = pos;
	}
	ft_memcpy((*stack)->array, array, ((*stack)->top_id + 1) * sizeof(*array));
	free(copy);
	free(array);
}