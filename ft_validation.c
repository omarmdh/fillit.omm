/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:40:04 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/21 14:34:16 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_check2(char ***t)
{
	int			i;
	int			j;
	int			k;
	int			x;

	k = -1;
	x = 0;
	while (t[++k] && (j = -1))
	{
		while (t[k][++j] && (i = -1))
			while (t[k][j][++i])
			{
				(i < 4 && t[k][j][i] == '#' && t[k][j][i + 1] == '#')
					? (x++) : (1);
				(i > 0 && t[k][j][i] == '#' && t[k][j][i - 1] == '#')
					? (x++) : (1);
				(j < 3 && t[k][j][i] == '#' && t[k][j + 1][i] == '#')
					? (x++) : (1);
				(j > 0 && t[k][j][i] == '#' && t[k][j - 1][i] == '#')
					? (x++) : (1);
			}
		if ((x != 8 && x != 6) || (x = 0))
			return (0);
	}
	return (1);
}

static	int		check(char *arr)
{
	int			i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] != '\n' && arr[i] != '#' && arr[i] != '.' && arr[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

static	int		ft_check(char *arr)
{
	int			i;
	int			n;
	int			p;
	int			s;
	int			t;

	i = 0;
	while (arr[i])
	{
		n = 0;
		t = -1;
		s = 0;
		p = 0;
		while (++t < 21 && arr[i])
		{
			(arr[i] == '#') ? (s++) : (0);
			(arr[i] == '.') ? (p++) : (0);
			(arr[i] == '\n') ? (n++) : (0);
			((ft_strlen(arr) - i) < 2) ? (n++) : (0);
			i++;
		}
		if (s != 4 || p != 12 || n != 5 || (ft_count_tetri(arr) > 26))
			return (0);
	}
	return (check(arr));
}

int				ft_validation(char *line, char ***tab)
{
	int			t1;
	int			t2;

	t1 = ft_check(line);
	if (t1 == 0)
	{
		free(line);
		ft_putendl("error");
		exit(0);
		return (0);
	}
	else
	{
		t2 = ft_check2(tab);
		if (t2 == 0)
		{
			ft_putendl("error");
			free(tab);
			free(line);
			exit(0);
			return (0);
		}
	}
	return (1);
}
