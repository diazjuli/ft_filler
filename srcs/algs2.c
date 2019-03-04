/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algs2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 21:36:21 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/18 22:48:05 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		go_vert(t_filler *fill, int inc, int x)
{
	int i;
	int end;

	i = fill->t.y;
	end = inc == -1 ? 0 : fill->board_n;
	while (i != end)
	{
		if (valid(fill, i, x) == 1)
		{
			fill->place.x = x;
			fill->place.y = i;
			return (1);
		}
		i += inc;
	}
	return (0);
}

int		go_hori(t_filler *fill, int inc, int y)
{
	int i;
	int end;

	i = fill->t.x;
	end = inc == -1 ? 0 : fill->board_m;
	while (i != end)
	{
		if (valid(fill, y, i) == 1)
		{
			fill->place.x = i;
			fill->place.y = y;
			return (1);
		}
		i += inc;
	}
	return (0);
}

int		final_alg(t_filler *fill)
{
	if (fill->algs == 6)
	{
		fill->t.x = fill->t.x == 0 ? fill->board_m - 5 : 5;
		fill->t.y = fill->t.y == 0 ? fill->board_n - 5 : 5;
		fill->algs++;
	}
	if (fill->algs == 7 && DIS_TARGET < fill->board_m / 10)
		fill->algs++;
	if (fill->algs == 8)
		update_comp(fill);
	update(fill, fill->t, AREA, AREA);
	return (algs1(fill));
}

int		next_corner(t_filler *fill)
{
	int		dis1;
	t_point temp;

	temp = fill->t;
	if (fill->algs == 4)
	{
		fill->t.x = fill->t.x == 0 ? fill->board_m - 1 : 0;
		temp.y = fill->t.y == 0 ? fill->board_n - 1 : 0;
		update(fill, fill->t, AREA, AREA);
		dis1 = DIS_TARGET;
		update(fill, temp, AREA, AREA);
		if (DIS(fill->me.y, fill->me.x, temp.y, temp.x) > dis1)
			fill->t = temp;
		update(fill, fill->t, AREA, AREA);
		fill->algs++;
	}
	else if (fill->algs == 5 && DIS_TARGET < fill->board_m / 8)
		fill->algs++;
	if (fill->algs > 5)
		return (final_alg(fill));
	update(fill, fill->t, AREA, AREA);
	return (algs1(fill));
}
