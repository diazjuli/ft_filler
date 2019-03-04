/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:37:18 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/18 22:47:30 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	update(t_filler *fill, t_point t, int dis_u, int dis_c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fill->board_n)
	{
		j = -1;
		while (++j < fill->board_m)
		{
			if (fill->board[i][j] == HIS(fill->player)
					|| fill->board[i][j] == LAST_PLAY(HIS(fill->player)))
			{
				fill->comp.x = DIS(i, j, t.y, t.x) < dis_c ? j : fill->comp.x;
				fill->comp.y = DIS(i, j, t.y, t.x) < dis_c ? i : fill->comp.y;
				dis_c = MIN(DIS(i, j, t.y, t.x), dis_c);
			}
			if (fill->board[i][j] == fill->player)
			{
				fill->me.x = DIS(i, j, t.y, t.x) < dis_u ? j : fill->me.x;
				fill->me.y = DIS(i, j, t.y, t.x) < dis_u ? i : fill->me.y;
				dis_u = MIN(DIS(i, j, t.y, t.x), dis_u);
			}
		}
	}
}

void	update_comp(t_filler *fill)
{
	int i;
	int j;

	i = 0;
	while (i < fill->board_n)
	{
		j = 0;
		while (j < fill->board_m)
		{
			if (fill->board[i][j] == LAST_PLAY(HIS(fill->player)))
			{
				fill->t.x = j;
				fill->t.y = i;
			}
			j++;
		}
		i++;
	}
}

int		read_token(t_filler *fill)
{
	int		n;
	int		i;
	char	*line;

	n = 6;
	i = 0;
	get_next_line(0, &line);
	fill->token_n = ft_atoi(&line[6]);
	while (ft_isdigit(line[n]))
		n++;
	n++;
	fill->token_m = ft_atoi(&line[n]);
	free(line);
	if (!(fill->token = (char **)malloc(sizeof(char *) * fill->token_n)))
		return (-1);
	while (i < fill->token_n)
	{
		get_next_line(0, &line);
		free(line);
		fill->token[i] = ft_strdup(line);
		i++;
	}
	return (0);
}

int		read_map(t_filler *fill)
{
	char	*line;
	int		i;

	i = 0;
	if (!(fill->board = (char **)malloc(sizeof(char *) * fill->board_n)))
		return (-1);
	get_next_line(0, &line);
	free(line);
	while (i < fill->board_n)
	{
		get_next_line(0, &line);
		fill->board[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	return (0);
}
