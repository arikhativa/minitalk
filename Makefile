# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 14:32:48 by yoav              #+#    #+#              #
#    Updated: 2022/08/05 15:08:18 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

# ft_printf
FT_PRINTF_DIR = libft

# libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT_HEAD_DIR = libft/libft
LIBFT  = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft

.PHONY: clean fclean re all

export ROOT = $(PWD)

all: $(NAME)

$(SERVER):
	$(MAKE) all -C ./server_src

$(CLIENT):

$(LIBFT):
	@$(MAKE) all -sC ./$(LIBFT_DIR)

$(NAME): $(SERVER)
	true
# @$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean:
	@$(MAKE) clean -sC ./$(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -sC ./$(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all
