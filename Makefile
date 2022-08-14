# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/14 13:05:48 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

# libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT_HEAD_DIR = $(addprefix $(LIBFT_DIR)/, libft)
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# ft_printf
FT_PRINTF_HEAD_DIR = $(LIBFT_DIR)

# libminitalk
LIBMINITALK_NAME = libminitalk.a
LIBMINITALK_DIR = libminitalk
LIBMINITALK_HEAD_DIR = $(addprefix $(LIBMINITALK_DIR)/, include)
LIBMINITALK_HEAD_NAME = define.h error.h minitalk_signal.h
LIBMINITALK_HEAD = $(addprefix $(LIBMINITALK_HEAD_DIR)/, $(LIBMINITALK_HEAD_NAME))
LIBMINITALK  = $(addprefix $(LIBMINITALK_DIR)/, $(LIBMINITALK_NAME))
LIBMINITALK_SRC = error_code.c minitalk_signal.c
LIBMINITALK_OBJ = $(addprefix $(LIBMINITALK_DIR)/src/, $(LIBMINITALK_SRC:.c=.o))

# server
SERVER_DIR = ./server_project
SERVER_HEAD_DIR = $(addprefix $(SERVER_DIR)/, include)
SERVER_HEAD = $(addprefix $(SERVER_HEAD_DIR)/, server.h)

SERVER_SRC = server.c \
	server_meta.c \
	server_signal.c \
	server_util.c

SERVER_OBJ = $(addprefix $(SERVER_DIR)/src/, $(SERVER_SRC:.c=.o))

# client
CLIENT_DIR = ./client_project
CLIENT_HEAD_DIR = $(addprefix $(CLIENT_DIR)/, include)
CLIENT_HEAD = $(addprefix $(CLIENT_HEAD_DIR)/, client.h)

CLIENT_SRC = client.c \
	client_meta.c \
	client_signal.c \
	input_is_valid.c \
	send_str.c
	
CLIENT_OBJ = $(addprefix $(CLIENT_DIR)/src/, $(CLIENT_SRC:.c=.o))

# general
CC = cc
ARFLAGS = rs
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

CFLAGS = -c -Wall -Werror -Wextra \
	-I$(SERVER_HEAD_DIR) \
	-I$(CLIENT_HEAD_DIR) \
	-I$(LIBFT_HEAD_DIR) \
	-I$(LIBMINITALK_HEAD_DIR) \
	-I$(FT_PRINTF_HEAD_DIR)

.PHONY: clean fclean re all pre_build

%.o: %.c $(CLIENT_HEAD_DIR) $(LIBFT_HEAD_DIR) $(LIBMINITALK_HEAD_DIR) \
	$(FT_PRINTF_HEAD_DIR) $(SERVER_HEAD_DIR)
	$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(LIBMINITALK)
	$(CC) $(LDFLAGS) $(CLIENT_OBJ) $(LIBMINITALK) $(LDLIBS) -o $@

$(SERVER): $(SERVER_OBJ) $(LIBFT) $(LIBMINITALK)
	$(CC) $(LDFLAGS) $(SERVER_OBJ) $(LIBMINITALK) $(LDLIBS) -o $@

$(LIBMINITALK): $(LIBMINITALK_OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT):
	$(MAKE) all -sC ./$(LIBFT_DIR)

clean:
	$(MAKE) clean -sC ./$(LIBFT_DIR)
	$(RM) $(SERVER_OBJ)
	$(RM) $(LIBMINITALK_OBJ)
	$(RM) $(CLIENT_OBJ)

fclean: clean
	$(MAKE) fclean -sC ./$(LIBFT_DIR)
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean all
