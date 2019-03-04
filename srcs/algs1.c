/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algs1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:01:38 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/18 22:48:16 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	update_target(t_filler *fill)
{
	if (fill->me.y < fill->t.y)
		fill->t.y = 0;
	else
		fill->t.y = fill->board_n - 1;
	if (fill->me.x < fill->t.x)
		fill->t.x = fill->board_m - 1;
	else
		fill->t.x = 0;
}

int		blocked_wall(t_filler *fill, t_point t)
{
	int i;

	i = 0;
	while (i < fill->board_n)
	{
		if (fill->board[i][t.x] == fill->player)
			return (1);
		i++;
	}
	i = 0;
	while (i < fill->board_m)
	{
		if (fill->board[t.y][i] == fill->player)
			return (1);
		i++;
	}
	return (0);
}

int		algs1(t_filler *fill)
{
	if (fill->me.y < fill->t.y)
	{
		if (fill->me.x == fill->t.x && go_vert(fill, -1, fill->t.x) == 1)
			return (1);
		if (fill->me.x < fill->t.x)
			return (dr(fill));
		else
			return (dl(fill));
	}
	if (fill->me.y == fill->t.y)
	{
		if (fill->me.x < fill->t.x && go_hori(fill, -1, fill->t.y) == 1)
			return (1);
		if (go_hori(fill, 1, fill->t.y) == 1)
			return (1);
	}
	if (fill->me.x == fill->t.x && go_vert(fill, 1, fill->t.x) == 1)
		return (1);
	if (fill->me.x < fill->t.x)
		return (fill->algs > 5 ? upright(fill) : ur(fill));
	else
		return (ul(fill));
}

int		algs(t_filler *fill)
{
	if (fill->algs == 0)
	{
		fill->t.x = fill->board_m / 2;
		fill->t.y = fill->board_n / 2;
		fill->algs++;
	}
	if (fill->algs == 1 && DIS_TARGET < fill->board_m / 10 + 2)
	{
		fill->algs++;
		update_target(fill);
	}
	if (fill->algs == 2 && blocked_wall(fill, fill->t) == 1)
	{
		fill->t.x = fill->t.x == 0 ? fill->board_m - 1 : 0;
		fill->t.y = fill->t.y == 0 ? fill->board_n - 1 : 0;
		fill->algs++;
	}
	if (fill->algs == 3 && blocked_wall(fill, fill->t))
		fill->algs++;
	if (fill->algs > 3)
		return (next_corner(fill));
	update(fill, fill->t, AREA, AREA);
	return (algs1(fill));
}
