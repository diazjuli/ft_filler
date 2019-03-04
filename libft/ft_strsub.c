/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:59:19 by jdiaz             #+#    #+#             */
/*   Updated: 2018/09/14 20:05:35 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*result;
	char const	*cpy;

	cpy = s;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (start-- > 0)
		cpy++;
	ft_strncpy(result, cpy, len);
	result[len] = '\0';
	return (result);
}
