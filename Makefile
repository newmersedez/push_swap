# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 19:28:22 by lorphan           #+#    #+#              #
#    Updated: 2021/09/07 20:01:55 by lorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
HEADER			= srcs/push_swap.h

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

SRCS_DIR		= srcs/
SRCS			= fill_stack.c sorting.c push_swap.c
SRCS_OBJS		= $(SRCS:.c=.o)

LIBFT_DIR		= libft/
LIBFT_SRCS		= ft_atoi.c ft_isdigit.c ft_itoa.c\
				ft_putchar_fd.c t_putnbr_fd.c ft_putstr_fd.c\
				ft_putchar.c ft_putnbr.c ft_putstr.c\
				ft_strcat.c ft_strlen.c
LIBFT_OBJS		= $(LIBFT_SRCS:.c=.o)

STACK_DIR		= stack/
STACK_SRCS		= push.c reverse_rotate.c rotate.c swap.c stack_utils.c
STACK_OBJS		= (STACK_SRCS:.c=.o)


