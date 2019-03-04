/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:01:40 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/18 22:48:24 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# define LAST_PLAY(P) ((P) == 'X' ? 'x' : 'o')
# define HIS(P) ((P) == 'X' ? 'O' : 'X')
# define ABS(X, Y) ((X) >= (Y) ? (X) - (Y) : (Y) - (X))
# define DIS(X, Y, x, y) (ABS(X, x) + ABS(Y, y))
# define DIS_TARGET (DIS(fill->me.y, fill->me.x, fill->t.y, fill->t.x))
# define DIS_COMP (DIS(fill->comp.y, fill->comp.x, fill->t.y, fill->t.x))
# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define AREA (fill->board_n + fill->board_m)

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_filler
{
	char	player;
	int		algs;
	int		board_m;
	int		board_n;
	char	**board;
	int		token_m;
	int		token_n;
	char	**token;
	t_point	me;
	t_point comp;
	t_point t;
	t_point place;
}				t_filler;

void			free_all(t_filler *fill);
int				read_map(t_filler *fill);
int				read_token(t_filler *fill);
int				algs(t_filler *fill);
void			update(t_filler *fill, t_point t, int dis_u, int dis_c);
int				valid(t_filler *fill, int i, int j);
void			place_token(t_filler *fill);
void			update_comp(t_filler *fill);
int				go_vert(t_filler *fill, int inc, int x);
int				go_hori(t_filler *fill, int inc, int y);
int				ul(t_filler *fill);
int				dl(t_filler *fill);
int				ur(t_filler *fill);
int				dr(t_filler *fill);
int				next_corner(t_filler *fill);
int				algs1(t_filler *fill);
void			update_target(t_filler *fill);
int				upright(t_filler *fill);

#endif
