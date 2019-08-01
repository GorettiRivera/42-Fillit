# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 09:26:55 by mrivera-          #+#    #+#              #
#    Updated: 2019/07/24 10:16:30 by mrivera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft/ fclean && make -C libft/ 
	clang -Wall -Wextra -Werror -I libft -o read.o -c read.c -g
	clang -Wall -Wextra -Werror -I libft -o tetromino.o -c tetromino.c -g
	clang -Wall -Wextra -Werror -I libft -o solve.o -c solve.c -g
	clang -Wall -Wextra -Werror -I libft -o main.o -c main.c -g
	clang -o fillit main.o read.o tetromino.o solve.o -I libft -L libft/ -lft 
	
clean:
	rm -rf *.o
	rm -rf fillit

fclean: clean
	@make -C libft/ fclean

re: fclean all