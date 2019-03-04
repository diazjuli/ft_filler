/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:55:32 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/18 22:47:46 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	place_token(t_filler *fill)
{
	ft_putnbr(fill->place.y);
	ft_putchar(' ');
	ft_putnbr(fill->place.x);
	ft_putchar('\n');
}

int		check_token(t_filler *fill, int i, int j)
{
	int		count;
	int		y;
	int		x;

	count = 0;
	y = 0;
	while (y < fill->token_n)
	{
		x = 0;
		while (x < fill->token_m)
		{
			if (fill->board[i + y][j + x] == fill->player
					&& fill->token[y][x] == '*')
				count++;
			if ((fill->board[i + y][j + x] == HIS(fill->player) ||
				fill->board[i + y][j + x] == LAST_PLAY(HIS(fill->player)))
					&& fill->token[y][x] == '*')
				return (0);
			x++;
		}
		y++;
	}
	return (count);
}

int		valid(t_filler *fill, int i, int j)
{
	if (i + fill->token_n > fill->board_n)
		return (0);
	else if (j + fill->token_m > fill->board_m)
		return (0);
	else
		return (check_token(fill, i, j));
}

void	free_all(t_filler *fill)
{
	int i;

	i = 0;
	while (i < fill->board_n)
	{
		free(fill->board[i]);
		i++;
	}
	free(fill->board);
	i = 0;
	while (i < fill->token_n)
	{
		free(fill->token[i]);
		i++;
	}
	free(fill->token);
}
