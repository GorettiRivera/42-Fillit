/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:27:02 by copinto-          #+#    #+#             */
/*   Updated: 2019/08/01 12:04:53 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define SIZE 4
# define TETRIMINO_SIZE 21
# define TETRIMINO_MAX_TOTAL 26
# define BUFFER_SIZE TETRIMINO_SIZE * TETRIMINO_MAX_TOTAL

int						g_num_tetris;
typedef struct			s_tetrimino
{
	char				letter;
	int					x[4];
	int					y[4];
	int					width;
	int					height;
	struct s_tetrimino	*next;
}						t_tetrimino;

char					**read_file(int fd);
char					**fillit_solve(t_tetrimino *tet);
char					**create_map(int size);
t_tetrimino				*tetrimino_map(char **map);

#endif
