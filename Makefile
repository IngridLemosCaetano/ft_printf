# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilemos-c <ilemos-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:27:07 by ilemos-c          #+#    #+#              #
#    Updated: 2025/08/21 13:27:59 by ilemos-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS =	printf.c \
		aux.c

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
