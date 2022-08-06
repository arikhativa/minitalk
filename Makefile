# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/06 13:40:34 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CLIENT = client

# server
SERVER_DIR = ./server_project
SERVER_OBJ = $(addprefix $(SERVER_DIR)/, server.a)

# client
CLIENT_DIR = ./client_project
CLIENT_OBJ = $(addprefix $(CLIENT_DIR)/, client.a)

# ft_printf
export FT_PRINTF_HEAD_DIR = libft

# libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft
export LIBFT_HEAD_DIR = libft/libft
LIBFT  = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# libminitalk
LIBMINITALK_NAME = libminitalk.a
LIBMINITALK_DIR = libminitalk
export LIBMINITALK_HEAD_DIR = libminitalk
LIBMINITALK  = $(addprefix $(LIBMINITALK_DIR)/, $(LIBMINITALK_NAME))

export CC = cc
export ARFLAGS = rs

LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

.PHONY: clean fclean re all

export ROOT = $(PWD)

all: $(NAME) $(CLIENT)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(LIBMINITALK)
	@$(MAKE) all -C $(CLIENT_DIR)
	@$(CC) $(LDFLAGS) $(CLIENT_OBJ) $(LDLIBS) -o $@

$(NAME): $(SERVER_OBJ) $(LIBFT) $(LIBMINITALK)
	@$(MAKE) all -C $(SERVER_DIR)
	@$(CC) $(LDFLAGS) $(SERVER_OBJ) $(LDLIBS) -o $@

$(LIBFT):
	@$(MAKE) all -sC ./$(LIBFT_DIR)

$(LIBMINITALK):
	@$(MAKE) all -sC ./$(LIBMINITALK_DIR)

clean:
	@$(MAKE) clean -sC ./$(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -sC ./$(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all
