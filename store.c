/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:59:19 by rliu              #+#    #+#             */
/*   Updated: 2017/10/22 01:45:15 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			store_xy(int a, int b, int i, t_triminos *tetriminos)
{
	if (i == 0)
	{
		tetriminos->y1 = a;
		tetriminos->x1 = b;
		tetriminos->y[i] = tetriminos->y1 - a;
		tetriminos->x[i] = tetriminos->x1 - b;
	}
	else
	{
		tetriminos->y[i] = a - tetriminos->y1;
		tetriminos->x[i] = b - tetriminos->x1;
	}
}

t_triminos		find_tetri(char **arr, t_triminos *tetriminos)
{
	int i;
	int a;
	int b;

	i = 0;
	a = 0;
	while (arr[a])
	{
		b = 0;
		while (arr[a][b])
		{
			if (arr[a][b] == '#')
			{
				store_xy(a, b, i, tetriminos);
				i++;
			}
			b++;
		}
		a++;
	}
	return (*tetriminos);
}

t_triminos		make_list(char *s, t_triminos *newtriminos)
{
	char		**arraytriminos;

	arraytriminos = ft_strsplit(s, '\n');
	newtriminos->alpha = g_alpha;
	find_tetri(arraytriminos, newtriminos);
	return (*newtriminos);
}
