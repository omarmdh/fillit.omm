/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:23:15 by ommadhi           #+#    #+#             */
/*   Updated: 2019/06/26 23:06:40 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		***ft_tetriline(char *line)
{
	int		i;
	int		j;
	char	***tab;
	char	**tab1;
	char	*str;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char **) * (ft_count_tetri(line) + 1));
	while (i < ft_count_tetri(line))
	{
		str = ft_strsub(line, j, 21);
		tab1 = ft_strsplit(str, '\n');
		tab[i] = tab1;
		free(str);
		j = j + 21;
		i++;
	}
	tab[ft_count_tetri(line)] = NULL;
	return (tab);
}
