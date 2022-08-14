# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/14 12:25:22 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client.a

HEAD_DIR = include
HEAD_NAME = include/client.h

SRC = src/client.c src/client_meta.c src/client_signal.c src/input_is_valid.c \
	src/send_str.c
OBJ = $(SRC:.c=.o)

CFLAGS = -c -Wall -Werror -Wextra \
	-I$(HEAD_DIR) \
	-I$(addprefix $(ROOT)/, $(LIBFT_HEAD_DIR)) \
	-I$(addprefix $(ROOT)/, $(LIBMINITALK_HEAD_DIR)) \
	-I$(addprefix $(ROOT)/, $(FT_PRINTF_HEAD_DIR))

.PHONY: clean fclean re all

%.o: %.c $(HEAD_NAME)
	@$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
