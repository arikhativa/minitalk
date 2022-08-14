# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/14 12:59:38 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libminitalk.a

HEAD_DIR = include
HEAD_NAME = include/define.h include/error.h include/minitalk_signal.h

# external headers
LIBFT_HEADER = $(addprefix $(ROOT)/, $(LIBFT_HEAD_DIR))
FT_PRINTF_HEADER = $(addprefix $(ROOT)/, $(FT_PRINTF_HEAD_DIR))

SRC = src/error_code.c src/minitalk_signal.c
OBJ = $(SRC:.c=.o)

CFLAGS = -c -Wall -Werror -Wextra \
	-I$(HEAD_DIR) \
	-I$(LIBFT_HEADER)\
	-I$(FT_PRINTF_HEADER)

.PHONY: clean fclean re all

%.o: %.c $(HEAD_NAME) $(FT_PRINTF_HEADER) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)
	
$(NAME): $(OBJ)

	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
