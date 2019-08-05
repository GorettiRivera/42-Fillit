/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 09:26:31 by mrivera-          #+#    #+#             */
/*   Updated: 2019/08/01 09:54:26 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		set_tetrimino(t_tetrimino *tet, char **map, int y, int x)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	while (tet->height > col)
	{
		row = 0;
		while (tet->width > row)
		{
			if (tet->x[i] == col && tet->y[i] == row)
			{
				map[col + y][row + x] = tet->letter;
				i += 1;
			}
			row += 1;
		}
		col += 1;
	}
}

int			check_placement(t_tetrimino *tet, char **map, int y, int x)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	col = 0;
	while (tet->height > col)
	{
		row = 0;
		while (tet->width > row)
		{
			if (tet->x[i] == col && tet->y[i] == row && i < SIZE)
			{
				if (map[col + y][row + x] != '.')
					return (0);
				i += 1;
			}
			row += 1;
		}
		col += 1;
	}
	set_tetrimino(tet, map, y, x);
	return (1);
}

void		move_tetrimino_upperleft(t_tetrimino *tet)
{
	int		i;
	int		pos_x;
	int		pos_y;

	while (tet)
	{
		i = -1;
		pos_x = SIZE - 1;
		pos_y = SIZE - 1;
		while (++i < SIZE)
		{
			if (tet->x[i] < pos_x)
				pos_x = tet->x[i];
			if (tet->y[i] < pos_y)
				pos_y = tet->y[i];
		}
		i = -1;
		while (++i < SIZE)
		{
			tet->x[i] -= pos_x;
			tet->y[i] -= pos_y;
		}
		tet = tet->next;
	}
}

int			solve_map(char **map, t_tetrimino *tet, int size)
{
	int		x;
	int		y;
	char	letter;

	if (!tet->next)
		return (1);
	y = -1;
	letter = tet->letter;
	while (++y <= (size - tet->height))
	{
		x = -1;
		while (++x <= (size - tet->width))
		{
			if (check_placement(tet, map, y, x))
			{
				if (solve_map(map, tet->next, size))
					return (1);
				tet->letter = '.';
				set_tetrimino(tet, map, y, x);
				tet->letter = letter;
			}
		}
	}
	return (0);
}

char		**fillit_solve(t_tetrimino *tet)
{
	char	**map;
	int		size;

	if (!tet)
		return (NULL);
	size = ft_sqrt(g_num_tetris * SIZE);
	map = create_map(size);
	move_tetrimino_upperleft(tet);
	while (!solve_map(map, tet, size))
	{
		ft_memdel((void **)map);
		size += 1;
		map = create_map(size);
	}
	return (map);
}
