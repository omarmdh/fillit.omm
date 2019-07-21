/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:17:55 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/21 14:19:17 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_tet(char ****tetri, char *line)
{
	int		ct;
	int		j;
	int		k;
	char	***tet;

	k = 0;
	tet = *tetri;
	ct = ft_count_tetri(line);
	while (k < ct)
	{
		j = 0;
		while (j <= 4)
		{
			free(tet[k][j]);
			j++;
		}
		free(tet[k]);
		k++;
	}
	free(tet[k]);
	free(tet);
	free(line);
}
