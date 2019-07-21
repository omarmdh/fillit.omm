/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 01:12:38 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/21 14:29:16 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		help_main(char *line, char ***tet)
{
	int		i;
	int		ct;

	i = -1;
	ct = ft_count_tetri(line);
	ft_validation(line, tet);
	while (++i < ct)
		ft_shift(&tet[i]);
	ft_plus_char(&tet);
}

int			main(int ac, char **av)
{
	int		fd;
	char	***tet;
	char	*line;
	char	**map;
	int		size;

	if (ac != 2)
		ft_putendl("usage: ./fillit [only one file]");
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	line = ft_readfile(fd);
	tet = ft_tetriline(line);
	help_main(line, tet);
	size = map_size(line);
	map = ft_map(size);
	while (solve(tet, map) == 0)
	{
		free_map(&map, size);
		map = ft_map(size++);
	}
	ft_print_tables(map);
	free_tet(&tet, line);
	free_map(&map, size);
	return (0);
}
