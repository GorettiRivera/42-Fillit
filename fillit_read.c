/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:26:43 by mrivera-          #+#    #+#             */
/*   Updated: 2019/07/24 11:13:56 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fillit_valid_characters(char *tetromino)
{
	int		i;
	int		height;
	int		blocks;
	int		characters;

	i = 0;
	blocks = 0;
	characters = 0;
	height = 0;
	while ((tetromino[i] == '.' || tetromino[i] == '#' || \
		tetromino[i] == '\n') && tetromino[i] && (height != SIZE))
	{
		if (tetromino[i] == '.' || tetromino[i] == '#')
		{
			if (tetromino[i] == '#')
				blocks += 1;
			characters += 1;
		}
		if (tetromino[i++] == '\n')
			height += 1;
	}
	if (((characters) == SIZE * SIZE) && (height == SIZE) && \
		(blocks == SIZE) && (tetromino[i] == '\n' || tetromino[i] == '\0'))
		return (1);
	return (0);
}

static int	fillit_valid_tetromino(char **tetromino)
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
			if (tetromino[row][col] == '#' && row < 3)
				tetromino[row + 1][col] == '#' ? cnt++ : cnt;
			if (tetromino[row][col] == '#' && row > 0)
				tetromino[row - 1][col] == '#' ? cnt++ : cnt;
			if (tetromino[row][col] == '#' && col < 3)
				tetromino[row][col + 1] == '#' ? cnt++ : cnt;
			if (tetromino[row][col] == '#' && col > 0)
				tetromino[row][col - 1] == '#' ? cnt++ : cnt;
		}
	}
	if (cnt == 6 || cnt == 8)
		return (1);
	return (0);
}

static int	fillit_valid(char *map)
{
	if (fillit_valid_characters(map))
		if (fillit_valid_tetromino((ft_strsplit(map, '\n'))))
			return (1);
	return (0);
}

char		**fillit_read(int fd)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * BUFFER_SIZE)))
		return (NULL);
	while (i < TETROMINO_MAX_TOTAL)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * TETROMINO_SIZE)))
			return (NULL);
		ft_bzero(map[i], TETROMINO_SIZE);
		if (!(read(fd, map[i], TETROMINO_SIZE)))
			return (map);
		if (!(fillit_valid(map[i])))
			return (NULL);
		i += 1;
		g_num_tets = i;
	}
	return (NULL);
}
