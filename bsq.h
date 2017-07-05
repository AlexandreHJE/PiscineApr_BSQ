/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:37:56 by jhu               #+#    #+#             */
/*   Updated: 2017/04/26 22:37:57 by jhu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct	s_point
{
	int size;
	int x;
	int y;
}				t_point;

typedef	struct	s_settings
{

	int		file;
	char	empty;
	char	obstacle;
	char	full;
	int		rows;
	int		cols;
	t_point	max;
}				t_settings;

t_settings		g_settings;

int				find(char *str, char c);
char			*ft_strcpy(char *dest, char *src);
int				fill_cell(int **arr, int row, int col, char c);

void			parse_settings();
int				readline(char *buf);
int				min(int a, int b, int c);
void			set_max(int size, int x, int y);
void			reset_settings();

#endif
