/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:12:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/12 19:30:33 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
static void	stack_print(t_stack *a)
{
	int	i;

	if (!a)
		return ;
	i = a->top_id;
	while (i >= 0)
	{
		printf("%d\n", a->array[i]);
		i--;
	}
	printf("\n\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !argv)
		exit(EXIT_SUCCESS);
	a = stack_create(argc - 1);
	b = stack_create(argc - 1);
	if (!a || !b || !a->array || !b->array)
		fail_exit(&a, &b);
	fill_stack_with_args(&a, &b, argc, argv);
	stack_print(a);
	sort(&a, &b);
	stack_print(a);
	success_exit(&a, &b);
	return (0);
}
