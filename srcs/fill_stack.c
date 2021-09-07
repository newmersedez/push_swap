/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:32:36 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 18:11:47 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_number(const char *str)
{
	size_t	i;
	size_t	length;

	if (!str)
		return (0);
	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fill_stack(t_stack **stack, int argc, char *argv[])
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (is_number(argv[i]))
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
