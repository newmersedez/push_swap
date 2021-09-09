/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:32:36 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/09 17:19:12 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_filling_error(t_stack **stack)
{
	ft_putstr("ERROR\n");
	stack_clear(stack);
	exit(1);
}

static int	is_correct_argument(const char *str)
{
	int		number_int;
	char	*number_str;

	if (!str)
		return (0);
	number_int = ft_atoi(str);
	number_str = ft_itoa(number_int);
	if (!number_str)
		return (0);
	if (ft_strcat(number_str, str))
	{
		free(number_str);
		return (0);
	}
	free(number_str);
	return (1);
}

static int	find_dublicates(int *array, size_t size)
{
	size_t	i;
	size_t	j;

	if (!array)
		return (0);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{		
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}		
	return (0);
}

static int	check_duplicates(t_stack **stack)
{
	int		i;
	int		*array;
	int		return_value;
	t_stack	*temp_stack;

	if (!stack || !*stack)
		return (0);
	array = (int *)malloc(stack_size(*stack) * sizeof(int));
	if (!array)
		handle_filling_error(stack);
	i = 0;
	temp_stack = *stack;
	while (temp_stack)
	{
		array[i] = temp_stack->data;
		temp_stack = temp_stack->next;
		i++;
	}
	return_value = find_dublicates(array, stack_size(*stack));
	free(array);
	return (return_value);
}

void	fill_stack(t_stack **stack, int argc, char *argv[])
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (is_correct_argument(argv[i]))
			push(stack, ft_atoi(argv[i]));
		else
			handle_filling_error(stack);
		i++;
	}
	if (check_duplicates(stack))
		handle_filling_error(stack);
}
