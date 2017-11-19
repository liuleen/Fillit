# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 10:14:45 by rliu              #+#    #+#              #
#    Updated: 2017/11/13 22:50:09 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = main.c store.c map.c read.c solve.c validate.c

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"
fclean:
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
