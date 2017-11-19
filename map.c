/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 23:11:37 by rliu              #+#    #+#             */
/*   Updated: 2017/10/27 22:00:43 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**smallest_map(void)
{
	char	**small_map;
	int		x;
	int		y;

	if (!(small_map = (char **)malloc(sizeof(char *) * (g_size + 1))))
		return (0);
	y = 0;
	small_map[y] = NULL;
	while (y < g_size)
	{
		if (!(small_map[y] = (char *)malloc(sizeof(char) * g_size + 1)))
			return (0);
		x = 0;
		while (x <= g_size)
		{
			small_map[y][x] = ((x < g_size) ? '.' : '\n');
			x++;
		}
		y++;
	}
	// small_map[y][x] = '\0';
	return (small_map);
}

void	print_map(char **map)
{
	int y;
	int x;

	y = 0;
	while (y < g_size)
	{
		x = 0;
		while (x <= g_size)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		y++;
	}
}
