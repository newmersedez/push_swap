# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 14:38:55 by lorphan           #+#    #+#              #
#    Updated: 2021/09/13 15:14:34 by lorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Utils
NAME				= push_swap

GCC					= gcc
FLAGS				= -Wall -Wextra -Werror
RM					= rm -rf

# Directories
SOURCES_DIR			= sources/
LIBFT_DIR			= libft/
STACK_DIR			= stack/

# Headers
SOURCES_HDR			= includes/push_swap.h
LIBFT_HDR			= includes/libft.h
STACK_HDR			= includes/stack_utils.h

# Sources and objects names
SRCS_NAMES			= big_sort.c errors.c filling.c index.c\
						push_swap.c small_sort.c sort_utils.c sort.c

LIBFT_SRCS_NAMES	= ft_itoa.c ft_memcpy.c ft_memset.c ft_putchar_fd.c\
						ft_atoi.c ft_bzero.c ft_putchar.c ft_putendl_fd.c\
						ft_putstr.c ft_putstr_fd.c ft_putendl.c\
						ft_strcmp.c ft_calloc.c ft_isdigit.c

STACK_SRCS_NAMES	= push.c reverse_rotate.c rotate.c stack_utils.c swap.c

OBJS_NAMES			= $(SRCS_NAMES:.c=.o)
LIBFT_OBJS_NAMES	= $(LIBFT_SRCS_NAMES:.c=.o)
STACK_OBJS_NAMES	= $(STACK_SRCS_NAMES:.c=.o)					

# Sources and objects

SRCS				= $(addprefix $(SOURCES_DIR), $(SRCS_NAMES))
LIBFT_SRCS			= $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS_NAMES))
STACK_SRCS			= $(addprefix $(STACK_DIR), $(STACK_SRCS_NAMES))

OBJS				= $(addprefix $(SOURCES_DIR), $(OBJS_NAMES))
LIBFT_OBJS		 	= $(addprefix $(LIBFT_DIR), $(LIBFT_OBJS_NAMES))
STACK_OBJS		 	= $(addprefix $(STACK_DIR), $(STACK_OBJS_NAMES))

# Rules

%.o:		%.c $(SOURCES_HDR) $(LIBFT_HDR) $(STACK_HDR)
			@gcc $(FLAGS) -I$(SOURCES_DIR) -c $< -o $(<:.c=.o)
			@gcc $(FLAGS) -I$(LIBFT_DIR) -c $< -o $(<:.c=.o)
			@gcc $(FLAGS) -I$(STACK_DIR) -c $< -o $(<:.c=.o)

all:					
