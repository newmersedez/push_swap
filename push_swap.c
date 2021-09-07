/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:45:29 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 17:09:50 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack/stack_utils.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	print(a);
	reverse_rotate_a(&a);
	print(a);
	clear(&a);
	clear(&b);
	return (0);
}
