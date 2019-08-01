/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:22:57 by mrivera-          #+#    #+#             */
/*   Updated: 2019/05/16 13:30:44 by mrivera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_strwhitespace(s[i]))
		i++;
	while (ft_strwhitespace(s[j - 1]))
		j--;
	if (i > j)
		j = i;
	return (ft_strsub(s, i, j - i));
}
