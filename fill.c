/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 22:37:22 by jhu               #+#    #+#             */
/*   Updated: 2017/04/26 22:37:22 by jhu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		find(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_elem(int **m, int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	return (m[i][j]);
}

int		fill_cell(int **arr, int row, int col, char c)
{
	if (c == g_settings.obstacle)
		arr[row][col] = 0;
	else if (c == g_settings.empty)
	{
		arr[row][col] = 1 + min(get_elem(arr, row, col - 1),
				get_elem(arr, row - 1, col - 1), get_elem(arr, row - 1, col));
		if (arr[row][col] > g_settings.max.size)
			set_max(arr[row][col], row, col);
	}
	else
		return (0);
	return (1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
