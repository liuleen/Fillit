/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:09:23 by rliu              #+#    #+#             */
/*   Updated: 2017/11/03 16:08:31 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char g_alpha = 'A';

t_triminos		*point_next(t_triminos *newtriminos)
{
	if (!(newtriminos->next = (t_triminos *)malloc(sizeof(t_triminos))))
		return (0);
	newtriminos = newtriminos->next;
	return (newtriminos);
}

t_triminos		*tetread(int fd)
{
	char		*buff;
	int			read_ret;
	int			last;
	t_triminos	*headtriminos;
	t_triminos	*newtriminos;

	buff = ft_strnew(21);
	if (!(headtriminos = (t_triminos *)malloc(sizeof(t_triminos))))
		return (0);
	newtriminos = headtriminos;
	while ((read_ret = read(fd, buff, 21)) >= 20)
	{
		last = read_ret;
		buff[read_ret] = '\0';
		if (chunk_valid(buff, read_ret) != 0)
			return (0);
		*newtriminos = make_list(buff, newtriminos);
		newtriminos = point_next(newtriminos);
		g_alpha++;
	}
	newtriminos->next = NULL;
	if (read_ret != 0 || last != 20)
		return (NULL);
	return (headtriminos);
}
