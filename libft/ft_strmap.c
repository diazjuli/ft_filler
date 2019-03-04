/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 19:31:52 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/01 19:16:45 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	index;

	index = 0;
	result = ft_strnew(ft_strlen(s));
	if (!result)
		return (NULL);
	while (s[index] != '\0')
	{
		result[index] = f(s[index]);
		index++;
	}
	return (result);
}
