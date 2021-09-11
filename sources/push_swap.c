/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:12:34 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 16:47:09 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
