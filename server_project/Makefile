# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/14 12:50:18 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server.a

HEAD_DIR = include
HEAD_NAME = 

SRC = src/server.c src/server_meta.c src/server_signal.c src/server_util.c
OBJ = $(SRC:.c=.o)

CFLAGS = 

.PHONY: clean fclean re all

%.o: %.c $(HEAD_NAME)
	$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
