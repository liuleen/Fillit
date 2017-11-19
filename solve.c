/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:56:09 by rliu              #+#    #+#             */
/*   Updated: 2017/11/03 21:00:58 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_piece(int x, int y, t_triminos *tetriminos, char **map)
{
	int i;
	int a;
	int b;

	i = 0;
	while (i < 4)
	{
		if ((g_size > tetriminos->y[i] + y) && (tetriminos->y[i] + y >= 0) &&
				(g_size > tetriminos->x[i] + x) && (tetriminos->x[i] + x >= 0))
		{
			a = tetriminos->y[i] + y;
			b = tetriminos->x[i] + x;
			if (map[a][b] != '.')
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

void	place_piece(int x, int y, char **map, t_triminos *tetriminos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[tetriminos->y[i] + y][tetriminos->x[i] + x] = tetriminos->alpha;
		i++;
	}
}

void	remove_piece(int x, int y, char **map, t_triminos *tetriminos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[tetriminos->y[i] + y][tetriminos->x[i] + x] = '.';
		i++;
	}
}

int		solve(t_triminos *tetriminos, char **map)
{
	int x;
	int y;

	y = 0;
	if (tetriminos->next == NULL)
		return (1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '.' && validate_piece(x, y, tetriminos, map))
			{
				place_piece(x, y, map, tetriminos);
				if (solve(tetriminos->next, map))
					return (1);
				remove_piece(x, y, map, tetriminos);
			}
			x++;
		}
		y++;
	}
	return (0);
}
