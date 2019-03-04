/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:47:53 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/18 22:51:44 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		main(void)
{
	char		*line;
	t_filler	*fill;

	if (!(fill = ft_memalloc(sizeof(t_filler))))
		return (-1);
	get_next_line(0, &line);
	fill->player = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	fill->algs = 0;
	free(line);
	while (1)
	{
		get_next_line(0, &line);
		fill->board_n = ft_atoi(&line[8]);
		fill->board_m = ft_atoi(&line[11]);
		free(line);
		read_map(fill);
		read_token(fill);
		if (algs(fill) == 0)
			break ;
		place_token(fill);
		free_all(fill);
	}
	free_all(fill);
	free(fill);
	return (0);
}
