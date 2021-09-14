/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:28:55 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/14 13:32:13 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insertion_sort(int *array, size_t size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < (int)size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		i++;
	}
}

static int	*create_copy_array(t_stack **a, t_stack **b)
{
	int		*dest;
	size_t	allocate_size;

	allocate_size = (*a)->top_id + 1;
	dest = (int *)malloc(allocate_size * sizeof(int));
	if (!dest)
		fail_exit(a, b);
	ft_memcpy(dest, (*a)->array, allocate_size * sizeof(int));
	insertion_sort(dest, allocate_size);
	return (dest);
}

void	set_index_numbers(t_stack **a, t_stack **b)
{
	int		i;
	size_t	pos;
	int		*copy_array;

	i = 0;
	copy_array = create_copy_array(a, b);
	while (i <= (*a)->top_id)
	{
		pos = 0;
		while (copy_array[pos] != (*a)->array[i])
			pos++;
		(*a)->array[i] = pos;
		i++;
	}
	free(copy_array);
}
