/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:26:31 by mrivera-          #+#    #+#             */
/*   Updated: 2019/07/24 10:58:08 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_map(char **map)
{
	size_t		i;
	size_t		len;

	i = -1;
	len = ft_strlen(*map);
	while (++i < len)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

int				main(int argc, char *argv[])
{
	int			fd;
	char		**map;
	t_tetromino *tetrominos;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("error\n");
		else if ((map = read_file(fd)) && (ft_strlen(map[0])) && \
				(!map[g_numTetris - 1][TETROMINO_SIZE - 1]))
		{
			tetrominos = tetromino_map(map);
			map = fillit_solve(tetrominos);
			print_map(map);
			free(tetrominos);
			ft_memdel((void **)map);

		}
		else
			ft_putstr("Error\n");
		close(fd);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" [file_name]\n");
	}
	return (0);
}