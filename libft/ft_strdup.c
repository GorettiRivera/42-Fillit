/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <mrivera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:29:23 by mrivera-          #+#    #+#             */
/*   Updated: 2019/08/01 09:57:00 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == 0)
	{
		return (NULL);
	}
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
