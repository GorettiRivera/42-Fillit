/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:42:39 by mrivera-          #+#    #+#             */
/*   Updated: 2019/08/01 09:54:26 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_map(int size)
{
	char	**map;
	int		row;
	int		col;

	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	row = 0;
	while (row < size)
	{
		if (!(map[row] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		row += 1;
	}
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
			map[row][col++] = '.';
		map[row][col] = '\0';
		row += 1;
	}
	return (map);
}

int			validate_characters(char *tetrimino)
{
	int		i;
	int		height;
	int		blocks;
	int		characters;

	i = 0;
	blocks = 0;
	characters = 0;
	height = 0;
	while ((tetrimino[i] == '.' || tetrimino[i] == '#' || \
		tetrimino[i] == '\n') && tetrimino[i] && (height != SIZE))
	{
		if (tetrimino[i] == '.' || tetrimino[i] == '#')
		{
			if (tetrimino[i] == '#')
				blocks += 1;
			characters += 1;
		}
		if (tetrimino[i++] == '\n')
			height += 1;
	}
	if (((characters) == SIZE * SIZE) && (height == SIZE) && \
		(blocks == SIZE) && (tetrimino[i] == '\n' || tetrimino[i] == '\0'))
		return (1);
	return (0);
}

int			validate_tetrimino(char **tetrimino)
{
	int		cnt;
	int		row;
	int		col;

	cnt = 0;
	row = -1;
	while (SIZE > ++row)
	{
		col = -1;
		while (SIZE > ++col)
		{
			if (tetrimino[row][col] == '#' && row < 3)
				tetrimino[row + 1][col] == '#' ? cnt++ : cnt;
			if (tetrimino[row][col] == '#' && row > 0)
				tetrimino[row - 1][col] == '#' ? cnt++ : cnt;
			if (tetrimino[row][col] == '#' && col < 3)
				tetrimino[row][col + 1] == '#' ? cnt++ : cnt;
			if (tetrimino[row][col] == '#' && col > 0)
				tetrimino[row][col - 1] == '#' ? cnt++ : cnt;
		}
	}
	if (cnt == 6 || cnt == 8)
		return (1);
	return (0);
}

int			validate_input(char *map)
{
	if (validate_characters(map))
		if (validate_tetrimino((ft_strsplit(map, '\n'))))
			return (1);
	return (0);
}

char		**read_file(int fd)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * BUFFER_SIZE)))
		return (NULL);
	while (i < TETRIMINO_MAX_TOTAL)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * TETRIMINO_SIZE)))
			return (NULL);
		ft_bzero(map[i], TETRIMINO_SIZE);
		if (!(read(fd, map[i], TETRIMINO_SIZE)))
			return (map);
		if (!(validate_input(map[i])))
			return (NULL);
		i += 1;
		g_num_tetris = i;
	}
	return (NULL);
}
