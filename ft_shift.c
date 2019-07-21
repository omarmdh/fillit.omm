/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:05:47 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/02 04:13:14 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_limit_up(char ***arr)
{
	char		**tet;
	int			i;
	int			j;

	tet = *arr;
	i = 0;
	j = 0;
	while (tet[j])
	{
		i = 0;
		while (tet[j][i])
		{
			if (tet[j][i] == '#')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

static	int		ft_limit_left(char ***arr)
{
	char		**tet;
	int			i;
	int			j;

	tet = *arr;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[j][i] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

static	void	ft_shift_up(char ***tet, int limit)
{
	int			i;
	int			j;
	char		**arr;

	arr = *tet;
	i = 0;
	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i] != '\0')
		{
			if (j > 0 && arr[j][i] == '#')
			{
				arr[j][i] = '.';
				arr[j - limit][i] = '#';
			}
			i++;
		}
		j++;
	}
}

static	void	ft_shift_left(char ***tet, int limit)
{
	int			i;
	int			j;
	char		**arr;

	arr = *tet;
	i = 0;
	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i] != '\0')
		{
			if (arr[j][i] == '#')
			{
				arr[j][i] = '.';
				arr[j][i - limit] = '#';
			}
			i++;
		}
		j++;
	}
}

void			ft_shift(char ***tet)
{
	char		**arr;
	int			limit;
	int			limit2;

	arr = *tet;
	limit = ft_limit_up(&arr);
	limit2 = ft_limit_left(&arr);
	ft_shift_up(&arr, limit);
	ft_shift_left(&arr, limit2);
}
