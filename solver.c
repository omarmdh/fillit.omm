/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:47:46 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/21 14:49:29 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_rmtet(char ***ma, char c)
{
	int		i;
	int		j;
	char	**map;

	map = *ma;
	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c && map[j][i] != '\n')
				map[j][i] = '.';
			i++;
		}
		j++;
	}
}

void		sharpos(char **tet, t_pos *pos)
{
	int		i;
	int		j;
	int		p;

	p = 0;
	i = 0;
	j = 0;
	while (tet[j] && p < 4)
	{
		i = 0;
		pos[p].i = 0;
		pos[p].j = 0;
		while (tet[j][i])
		{
			if (ft_isalpha(tet[j][i]) == 1)
			{
				pos[p].i = i;
				pos[p].j = j;
				p++;
			}
			i++;
		}
		j++;
	}
}

int			check_place(char **map, t_pos *pos, t_pos ij)
{
	int		p;
	int		size;

	size = ft_strlen(map[0]);
	p = 0;
	while (p < 4)
	{
		if (!((pos[p].j + ij.j < size) && (pos[p].i + ij.i < size) &&
					(map[pos[p].j + ij.j][pos[p].i + ij.i] == '.')))
			return (0);
		p++;
	}
	return (1);
}

int			put_tet(char **map, t_pos *pos, t_pos ij, char **tet)
{
	int		p;
	int		size;
	char	c;

	c = tet[pos[0].j][pos[0].i];
	size = ft_strlen(map[0]);
	p = 0;
	while (p < 4)
	{
		map[pos[p].j + ij.j][pos[p].i + ij.i] = tet[pos[0].j][pos[0].i];
		p++;
	}
	return (1);
}

int			solve(char ***tet, char **map)
{
	t_pos	ij;
	char	c;
	t_pos	pos[4];

	if (tet[0] == NULL)
		return (1);
	sharpos(tet[0], pos);
	c = tet[0][pos[0].j][pos[0].i];
	ij.j = -1;
	while (map[++ij.j])
	{
		ij.i = 0;
		while (map[ij.j][ij.i])
		{
			if ((check_place(map, pos, ij)) == 1)
			{
				put_tet(map, pos, ij, tet[0]);
				if (solve(&tet[1], map) == 1)
					return (1);
				ft_rmtet(&map, c);
			}
			ij.i++;
		}
	}
	return (0);
}
