/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 00:17:23 by ommadhi           #+#    #+#             */
/*   Updated: 2019/06/26 22:10:01 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_readfile(const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	char	*arr;
	int		ret;

	arr = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = arr;
		arr = ft_strjoin(arr, buff);
		free(tmp);
	}
	if (!(ft_strchr(arr, '\n')))
	{
		ft_putendl("error");
		exit(0);
	}
	return (arr);
}
