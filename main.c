/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:36:38 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/07 15:28:06 by lorphan          ###   ########.fr       */
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
	push(&b, 12);
	push(&b, -12);
	push(&a, 123);

	print(a);
	print(b);
	return (0);
}
