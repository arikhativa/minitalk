# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/09 14:12:18 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

# server
SERVER_DIR = ./server_project
SERVER_SRC = $(wildcard $(SERVER_DIR)/*.c)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

# client
CLIENT_DIR = ./client_project
CLIENT_SRC = $(wildcard $(CLIENT_DIR)/*.c)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# common_util
UTIL_DIR = ./common_util
UTIL_SRC = $(wildcard $(UTIL_DIR)/*.c)
UTIL_OBJ = $(UTIL_SRC:.c=.o)

# ft_printf
FT_PRINTF_HEAD_DIR = libft

# libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT_HEAD_DIR = libft/libft
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# headers
ALL_HEADERS =  \
	./client_project/client.h \
	./client_project/input.h \
	./libft/include/handler.h \
	./libft/include/printable_mem.h \
	./libft/include/list.h \
	./libft/include/flag.h \
	./libft/include/count.h \
	./libft/include/base.h \
	./libft/include/convert.h \
	./libft/include/generic.h \
	./libft/include/define.h \
	./libft/include/print.h \
	./libft/include/ft_printf_input.h \
	./libft/libft/libft.h \
	./libft/ft_printf.h \
	./server_project/server.h \
	./common_util/signal.h \
	./common_util/error.h \
	./common_util/define.h

CC = cc
CFLAGS = -c \
	-I$(SERVER_DIR) \
	-I$(CLIENT_DIR) \
	-I$(UTIL_DIR) \
	-I$(LIBFT_HEAD_DIR) \
	-I$(FT_PRINTF_HEAD_DIR)
#-Wall -Werror -Wextra

ARFLAGS = rs
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft 

.PHONY: clean fclean re all

%.o: %.c $(ALL_HEADERS)
	@$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_OBJ) $(UTIL_OBJ) $(LIBFT) 
	@$(CC) $(LDFLAGS) $(CLIENT_OBJ) $(UTIL_OBJ) $(LDLIBS) -o $@

$(SERVER): $(SERVER_OBJ) $(UTIL_OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) $(SERVER_OBJ) $(UTIL_OBJ) $(LDLIBS) -o $@

$(LIBFT):
	@$(MAKE) all -sC ./$(LIBFT_DIR)

clean:
	@$(MAKE) clean -sC ./$(LIBFT_DIR)
	@$(RM) $(SERVER_OBJ)
	@$(RM) $(CLIENT_OBJ)

fclean: clean
	@$(MAKE) fclean -sC ./$(LIBFT_DIR)
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)

re: fclean all
