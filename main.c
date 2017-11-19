/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:04:05 by rliu              #+#    #+#             */
/*   Updated: 2017/11/03 16:14:06 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		g_size = 2;

int		error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		main(int argc, char **argv)
{
	t_triminos		*tetriminos;
	t_triminos		*count_triminos;
	int				fd;
	char			**map;
	int				list_count;

	if (((argc != 2) || ((fd = open(argv[1], O_RDONLY)) < 0)) ||
		((tetriminos = tetread(fd)) == NULL))
		return (error());
	count_triminos = tetriminos;
	list_count = 0;
	while (count_triminos->next != '\0')
	{
		list_count++;
		count_triminos = count_triminos->next;
	}
	while ((list_count * 4) > (g_size * g_size))
		g_size++;
	while (!(solve(tetriminos, (map = smallest_map()))))
	{
		free(map);
		g_size++;
	}
	print_map(map);
	free(map);
	return (0);
}
