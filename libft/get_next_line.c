/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:43:07 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/15 14:40:38 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>

int		ft_line(char **str, char **line, int fd, int r)
{
	char	*temp;
	int		n;

	n = 0;
	while (str[fd][n] != '\n' && str[fd][n] != '\0')
		n++;
	if (str[fd][n] == '\n')
	{
		temp = ft_strdup(str[fd] + n + 1);
		*line = ft_strsub(str[fd], 0, n);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][n] == '\0')
	{
		if (r == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char static	*str[42];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			r;

	ft_bzero(buf, BUFF_SIZE + 1);
	if (fd < 0 || line == NULL)
		return (-1);
	str[fd] = str[fd] == NULL ? ft_strnew(1) : str[fd];
	while (ft_strchr(str[fd], '\n') == NULL &&
			(r = read(fd, buf, BUFF_SIZE) > 0))
	{
		buf[BUFF_SIZE] = '\0';
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		ft_bzero(buf, BUFF_SIZE);
	}
	if (r < 0)
		return (-1);
	else if (r == 0 && str[fd][0] == '\0')
		return (0);
	return (ft_line(str, line, fd, r));
}
