/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:14:00 by rliu              #+#    #+#             */
/*   Updated: 2017/10/26 14:42:29 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_triminos
{
	int					x1;
	int					y1;
	int					x[4];
	int					y[4];
	char				alpha;
	struct s_triminos	*next;
}					t_triminos;

int					error(void);
t_triminos			*tetread(int fd);
t_triminos			*point_next(t_triminos *newtriminos);
int					chunk_valid(char *s, int count);
int					check_hashes(char *s);
int					store_list(char *s, t_triminos *tetriminos);
t_triminos			make_list(char *s, t_triminos *tetriminos);
t_triminos			find_tetri(char **arr, t_triminos *tetriminos);
void				store_xy(int a, int b, int i, t_triminos *tetriminos);
char				**smallest_map();
void				print_map(char **map);
int					solve(t_triminos *tetriminos, char **map);
void 				place_piece(int x, int y, char **map,
					t_triminos *tetriminos);
int 				validate_piece(int x, int y, t_triminos *tetriminos,
					char **map);

extern	int			g_size;
extern	char		g_alpha;
#endif
