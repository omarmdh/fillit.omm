/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:43:28 by ommadhi           #+#    #+#             */
/*   Updated: 2019/06/26 23:08:03 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetri(char *line)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] == '\n' && line[i + 1] == '\n') || (line[i + 1] == '\0'))
			c++;
		i++;
	}
	return (c);
}
