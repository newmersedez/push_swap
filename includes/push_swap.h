/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:17:07 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/10 18:28:23 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_utils.h"
# include "libft.h"

t_stack	*fill_stack_with_args(int argc, char *argv[]);
void	clear_stacks(t_stack **a, t_stack **b);
void	emergency_exit(t_stack **a, t_stack **b);
void	good_exit(t_stack **a, t_stack **b);

#endif