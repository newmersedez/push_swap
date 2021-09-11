/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:59:19 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 17:04:54 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
static int	is_correct_arguments(int argc, char *argv[])
{
	size_t	i;
	int		number_in_int;
	char	*number_in_str;

	i = 1;
	while (i < (size_t)argc)
	{
		number_in_int = ft_atoi(argv[i]);
		number_in_str = ft_itoa(number_in_int);
		if (ft_strcmp(number_in_str, argv[i]))
		{
			free(number_in_str);
			return (0);
		}
		free(number_in_str);
		i++;
	}
	return (1);
}

static int	is_unique_arguments(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	int		curr_number;
	int		prev_number;

	i = 1;
	while (i < (size_t)argc)
	{
		j = 1;
		curr_number = ft_atoi(argv[i]);
		while (j < i)
		{
			prev_number = ft_atoi(argv[j]);
			if (prev_number == curr_number)
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

static int	is_sorted_arguments(int argc, char *argv[])
{
	size_t	i;
	int		curr_number;
	int		next_number;

	i = 1;
	while (i < (size_t)argc - 1)
	{
		curr_number = ft_atoi(argv[i]);
		next_number = ft_atoi(argv[i + 1]);
		if (curr_number > next_number)
			return (0);
		i++;
	}
	return (1);
}

void	fill_stack_with_args(t_stack **a, int argc, char *argv[])
{
	size_t	i;

	if (!is_correct_arguments(argc, argv))
		fail_exit(NULL, NULL);
	if (!is_unique_arguments(argc, argv))
		fail_exit(NULL, NULL);
	if (is_sorted_arguments(argc, argv))
		exit(EXIT_SUCCESS);
	i = argc - 1;
	while (i > 0)
	{
		push(a, ft_atoi(argv[i]));
		i--;
	}
}
