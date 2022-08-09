# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/09 13:11:15 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

NAME = minitalk

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
export LIBMINITALK_HEAD_DIR = $(addprefix $(LIBMINITALK_DIR)/, include)
LIBMINITALK  = $(addprefix $(LIBMINITALK_DIR)/, $(LIBMINITALK_NAME))

export CC = cc
export ARFLAGS = rs

LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft 

.PHONY: clean fclean re all $(SERVER_OBJ) $(CLIENT_OBJ) $(LIBMINITALK)

export ROOT = $(PWD)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(LIBMINITALK)
	@$(CC) $(LDFLAGS) $(CLIENT_OBJ) $(LIBMINITALK) $(LDLIBS) -o $@

$(SERVER): $(SERVER_OBJ) $(LIBFT) $(LIBMINITALK)
	$(CC) $(LDFLAGS) $(SERVER_OBJ) $(LIBMINITALK) $(LDLIBS) -o $@

$(CLIENT_OBJ):
	@$(MAKE) all -C $(CLIENT_DIR)

$(SERVER_OBJ): 
	@$(MAKE) all -C $(SERVER_DIR)

$(LIBMINITALK):
	@$(MAKE) all -sC ./$(LIBMINITALK_DIR)

$(LIBFT):
	@$(MAKE) all -sC ./$(LIBFT_DIR)

clean:
	@$(MAKE) clean -sC ./$(LIBFT_DIR)
	@$(MAKE) clean -sC ./$(CLIENT_DIR)
	@$(MAKE) clean -sC ./$(SERVER_DIR)
	@$(MAKE) clean -sC ./$(LIBMINITALK_DIR)

fclean: clean
	@$(MAKE) fclean -sC ./$(LIBFT_DIR)
	@$(MAKE) fclean -sC ./$(CLIENT_DIR)
	@$(MAKE) fclean -sC ./$(SERVER_DIR)
	@$(MAKE) fclean -sC ./$(LIBMINITALK_DIR)
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)

re: fclean all
