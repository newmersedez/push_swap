/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:45:29 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 17:40:25 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	a = NULL;
	b = NULL;
	fill_stack(&a, argc, argv);
	print(a);
	return (0);
}
