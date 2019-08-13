# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 10:01:03 by viduvern          #+#    #+#              #
#    Updated: 2019/08/13 15:10:38 by viduvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
LIB = libft/libft.a
SRC =  srcs/main.c \
	   srcs/error.c \
	   srcs/hash.c \
	   srcs/adjlist.c \
	   srcs/ezfuct.c \
	   srcs/free.c \
	   srcs/print.c \
	   srcs/bfs.c \
	   srcs/utils_queue.c \
	   srcs/queue.c \
	   srcs/dispatch.c \

FLAG = -Wall -Werror -Wextra -g -fsanitize=address -I includes/ 
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

libft:
	@make -C libft/ re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CB)[lem_in] :$(CE) $(CG)Creating Library$(CE)";
	@cp libft/libft.a .
	@echo "$(CB)[lem_in] :$(CE) $(CG)Compiling lem_in ...$(CE)";
	@gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

%.o: %.c
	@echo "$(CB)[lem_in] :$(CE) $(CG)Compiling $<$(CE)";
	@gcc $(FLAG) -c $< -o $@

clean: 
	@echo "$(CB)[lem_in] :$(CE) $(CG)Cleaning Library ...$(CE)";
	-@make -C libft nohdclean
	@echo "$(CB)[lem_in] :$(CE) $(CG)Cleaning lem_in objects$(CE)";
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "$(CB)[lem_in] :$(CE) $(CY)Cleaning lem_in ...$(CE)";
	@/bin/rm -f $(NAME)

totclean: fclean
	@make -C libft/ fclean

re: fclean all
	
total: fclean libft all

.PHONY: all clean fclean re libft
