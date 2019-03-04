/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:44:08 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/18 22:47:55 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		dl(t_filler *fill)
{
	int		i;
	int		j;

	j = 0;
	while (j < fill->board_m)
	{
		i = fill->board_n - 1;
		while (i >= 0)
		{
			if (valid(fill, i, j) == 1)
			{
				fill->place.x = j;
				fill->place.y = i;
				return (1);
			}
			i--;
		}
		j++;
	}
	return (0);
}

int		upright(t_filler *fill)
{
	int i;
	int j;
	int alt;

	alt = 1;
	j = fill->board_m - 1;
	i = 0;
	while (i < fill->board_n || j > -1)
	{
		if (valid(fill, i, j) == 1)
		{
			fill->place.x = j;
			fill->place.y = i;
			return (1);
		}
		if (alt == 1 && j > -1)
			j--;
		else if (i < fill->board_n)
			i++;
		alt = alt == -1 ? 1 : -1;
	}
	return (ur(fill));
}

int		ur(t_filler *fill)
{
	int		i;
	int		j;

	j = fill->board_m - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < fill->board_n)
		{
			if (valid(fill, i, j) == 1)
			{
				fill->place.x = j;
				fill->place.y = i;
				return (1);
			}
			i++;
		}
		j--;
	}
	return (0);
}

int		dr(t_filler *fill)
{
	int		i;
	int		j;

	i = fill->board_n - 1;
	while (i >= 0)
	{
		j = fill->board_m - 1;
		while (j >= 0)
		{
			if (valid(fill, i, j) == 1)
			{
				fill->place.x = j;
				fill->place.y = i;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int		ul(t_filler *fill)
{
	int		i;
	int		j;

	j = 0;
	while (j < fill->board_m)
	{
		i = 0;
		while (i < fill->board_n)
		{
			if (valid(fill, i, j) == 1)
			{
				fill->place.x = j;
				fill->place.y = i;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
