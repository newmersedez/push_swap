/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:17:44 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/11 17:03:47 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_putendl(char *s);
void	ft_putchar(char c);
char	*ft_itoa(int n);
#endif