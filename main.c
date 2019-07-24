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

int				main(int argc, char *argv[])
{
	int			fd;
	char		**map;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("error\n");
		else if ((map = fillit_read(fd)) && (ft_strlen(map[0])) && \
				(!map[g_num_tets - 1][TETROMINO_SIZE - 1]))
		{
			ft_putstr("OK");
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
