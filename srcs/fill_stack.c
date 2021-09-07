/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:32:36 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 19:25:46 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	fill_stack(t_stack **stack, int argc, char *argv[])
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (is_correct_argument(argv[i]))
			push(stack, ft_atoi(argv[i]));
		else
		{
			ft_putstr("ERROR\n");
			clear(stack);
			exit(1);
		}
		i++;
	}
}
