/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:35:01 by lorphan           #+#    #+#             */
/*   Updated: 2021/09/13 12:35:02 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	symbol;

	i = 0;
	ptr = (unsigned char *)b;
	symbol = (unsigned char)c;
	while (i < len)
	{
		*(ptr + i) = symbol;
		i++;
	}
	return (b);
}
