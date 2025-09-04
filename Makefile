# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evillca- <evillca-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 14:56:10 by evillca-          #+#    #+#              #
#    Updated: 2025/07/14 14:56:10 by evillca-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Iutils

SRC = main.c \
      sorting/indexer.c \
      utils/errors.c \
      utils/validation.c \
      parsing/parser.c \
      sorting/sort_small.c \
      stack/operations1.c \
      stack/operations2.c \
      sorting/sort_k.c

OBJ = $(SRC:.c=.o)

DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)

valgrind: re
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) $(ARG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
