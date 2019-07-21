/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:59:07 by ommadhi           #+#    #+#             */
/*   Updated: 2019/07/21 14:53:00 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 10

typedef struct	s_pos
{
	int			i;
	int			j;
}				t_pos;

void			free_tet(char ****tetri, char *line);
int				solve(char ***tet, char **map);
void			free_map(char ***ma, int size);
char			**ft_map(int size);
char			*ft_readfile(const int fd);
int				ft_count_tetri(char *line);
char			***ft_tetriline(char *line);
int				ft_validation(char *line, char ***arr);
void			ft_shift(char ***tet);
void			ft_plus_char(char ****tet);
char			**mapi(char *line, char ***tet);
void			ft_rmtet(char ***ma, char c);
void			sharpos(char **tet, t_pos *pos);
int				check_place(char **map, t_pos *pos, t_pos ij);
int				put_tet(char **map, t_pos *pos, t_pos ij, char **tet);
int				map_size(char *arr);

#endif
