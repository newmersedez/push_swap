/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:36:38 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 16:10:59 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack/stack_utils.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);	
	print(a);
	printf("\nRotated\n");
	rotate_b(&a);
	print(a);
	return (0);
}
