# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 09:26:55 by mrivera-          #+#    #+#              #
#    Updated: 2019/08/01 11:45:46 by mrivera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft
SRCS = main.c read.c tetromino.c solve.c 
OBJS = *.o
LIB_DIR = libft/

$(NAME):
	make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -I $(INCLUDES) -L $(LIB_DIR) -lft

all: $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

fclean: clean
	make -C $(LIB_DIR) fclean
	
re:	fclean all