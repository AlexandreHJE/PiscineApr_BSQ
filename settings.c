/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:37:39 by jhu               #+#    #+#             */
/*   Updated: 2017/04/26 22:37:41 by jhu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	parse_settings(void)
{
	int		len;
	int		i;
	char	settings_str[16];

	len = readline(settings_str);
	g_settings.full = settings_str[--len];
	g_settings.obstacle = settings_str[--len];
	g_settings.empty = settings_str[--len];
	i = 0;
	while (i < len)
		g_settings.rows = g_settings.rows * 10 + settings_str[i++] - '0';
}

int		readline(char *buf)
{
	char	c;
	int		i;

	c = '\0';
	i = 0;
	while (c != '\n')
	{
		read(g_settings.file, &c, 1);
		buf[i++] = c;
	}
	buf[--i] = '\0';
	return (i);
}

void	set_max(int size, int x, int y)
{
	g_settings.max.size = size;
	g_settings.max.x = x;
	g_settings.max.y = y;
}

int		min(int a, int b, int c)
{
	int		m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	reset_settings(void)
{
	g_settings = (const t_settings){0, 0, 0, 0, 0, 0, {0, 0, 0}};
}
