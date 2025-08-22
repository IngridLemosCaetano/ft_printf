# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:27:07 by ilemos-c          #+#    #+#              #
#    Updated: 2025/08/22 18:10:09 by ingrid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS =	ft_printf.c \
		ft_printf_basic.c \
		ft_printf_unsigned_hex.c\
		ft_printf_pointer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	$(CC) -g printf.c libft.c auxiliary.c -o printf_debug
