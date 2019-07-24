/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:27:02 by mrivera-          #+#    #+#             */
/*   Updated: 2019/07/24 10:49:51 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define SIZE 4
# define TETROMINO_SIZE 21
# define TETROMINO_MAX_TOTAL 26
# define BUFFER_SIZE TETROMINO_SIZE * TETROMINO_MAX_TOTAL

int		g_num_tets;
char					**fillit_read(int fd);

#endif
