# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/05 15:08:27 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

# ft_printf
FT_PRINTF_DIR = ../libft

# libft
LIBFT_DIR = ../libft
LIBFT_HEAD_DIR = $(addprefix $(LIBFT_DIR)/, libft)

# server
HEAD_DIR = include
HEAD_NAME = $(wildcard include/*.h)

SRC = $(wildcard src/**/*.c)
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -c -I$(LIBFT_HEAD_DIR) -I$(HEAD_DIR) -I$(FT_PRINTF_DIR)
# CFLAGS = -c -Wall -Werror -Wextra -I$(LIBFT_HEAD_DIR) -I$(HEAD_DIR) -I$(FT_PRINTF_DIR)

.PHONY: clean fclean re all

%.o: %.c $(HEAD_NAME)
	@$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
