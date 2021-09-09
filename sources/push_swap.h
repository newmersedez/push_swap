/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:14:35 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/09 18:52:04 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../stack/stack_utils.h"
# include "../libft/libft.h"

void	handle_error(t_stack **stack);
void	fill_stack_with_args(t_stack **stack, int argc, char *argv[]);
void	start_sorting(t_stack **a, t_stack **b);

#endif