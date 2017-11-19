/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:47:33 by rliu              #+#    #+#             */
/*   Updated: 2017/10/22 01:29:56 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_hashes(char *s)
{
	int		i;
	int		connect;

	i = 0;
	connect = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if ((i + 5 < 20) && (s[i + 5] == '#'))
				connect++;
			if ((i - 5 >= 0) && (s[i - 5] == '#'))
				connect++;
			if ((i + 1 < 20) && (s[i + 1] == '#'))
				connect++;
			if ((i - 1 >= 0) && (s[i - 1] == '#'))
				connect++;
		}
		i++;
	}
	if (connect == 6 || connect == 8)
		return (0);
	return (1);
}

int			chunk_valid(char *s, int count)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (s[i] != '#' && s[i] != '.')
				return (1);
			if (s[i] == '#' && ++hash > 4)
				return (1);
		}
		else if (s[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && s[20] != '\n')
		return (1);
	if (check_hashes(s) == 1)
		return (1);
	return (0);
}
