# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/14 12:24:24 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libminitalk.a

HEAD_DIR = include
HEAD_NAME = include/define.h include/error.h include/minitalk_signal.h

SRC = src/error_code.c src/minitalk_signal.c
OBJ = $(SRC:.c=.o)

CFLAGS = -c -Wall -Werror -Wextra \
	-I$(HEAD_DIR) \
	-I$(addprefix $(ROOT)/, $(LIBFT_HEAD_DIR)) \
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
