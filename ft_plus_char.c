/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 00:10:38 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/02 04:00:05 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_plus_char(char ****tet)
{
	char	c;
	char	***arr;
	int		i;
	int		j;
	int		k;

	arr = *tet;
	c = 'A' - 1;
	j = 0;
	k = -1;
	while (arr[++k] && c++)
	{
		j = 0;
		while (arr[k][j])
		{
			i = 0;
			while (arr[k][j][i])
			{
				if (arr[k][j][i] == '#')
					arr[k][j][i] = c;
				i++;
			}
			j++;
		}
	}
}
