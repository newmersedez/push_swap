/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:12:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 18:28:51 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// static void	stack_print(t_stack *a)
// {
// 	if (!a)
// 		return;
// 	while (a)
// 	{
// 		printf("%d\n", a->data);
// 		a = a->next;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !argv)
		exit(EXIT_SUCCESS);
	a = NULL;
	b = NULL;
	fill_stack_with_args(&a, argc, argv);
	sort(&a, &b);
	success_exit(&a, &b);
	return (0);
}
