# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 11:38:01 by amechain          #+#    #+#              #
#    Updated: 2023/01/11 15:18:51 by amechain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRC = push_swap.c \
        array_get.c \
        check.c \
        complex_algo.c \
        free.c \
        initialize.c \
        sort.c \
        operations.c \
        simple_algo.c \
        utils.c

SRCS = $(addprefix ./sources/, $(SRC))

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./includes/libft

LIBFT_NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT_NAME)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT_DIR)/$(LIBFT_NAME):
	make -sC $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./includes/libft
	@rm -f $(OBJS)

fclean: clean
	make fclean -C ./includes/libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
