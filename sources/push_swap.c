/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:12:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 21:01:54 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	print(t_stack *a)
{
	int i;
	
	if (!a || a->top_id == -1)
		return ;
	i = a->top_id;
	while (i > -1)
	{
		printf("%d\n", a->array[i]);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !argv)
		exit(EXIT_SUCCESS);
	a = stack_create(10);
	b = stack_create(10);
	if (!a || !b || !a->array || !b->array)
		fail_exit(&a, &b);
	// fill_stack_with_args(&a, argc, argv);
	success_exit(&a, &b);
	return (0);
}
