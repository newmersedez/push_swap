/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:12:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 21:04:56 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	fill_stack_with_args(&a, argc, argv);
	//sort(&a, &b);
	success_exit(&a, &b);
	return (0);
}
