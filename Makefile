# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 21:13:43 by gostroum          #+#    #+#              #
#    Updated: 2025/05/11 15:12:41 by gostroum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SOURCES = ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
