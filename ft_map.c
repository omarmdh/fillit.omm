/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 21:00:39 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/21 14:21:18 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_size(char *arr)
{
	int		countet;
	int		i;

	i = 2;
	countet = ft_count_tetri(arr);
	while (i * i < countet * 4)
		i++;
	return (i);
}

char		**ft_map(int size)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		i = 0;
		map[j] = ft_strnew(size);
		while (i < size)
		{
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	map[j] = NULL;
	return (map);
}

void		free_map(char ***ma, int size)
{
	int		i;
	char	**map;

	i = 0;
	map = *ma;
	while (i < size)
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(map);
}
