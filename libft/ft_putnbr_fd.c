/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:25:57 by jdiaz             #+#    #+#             */
/*   Updated: 2018/10/01 21:32:51 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_neg_fd(int *nb, int fd)
{
	ft_putchar('-');
	if (*nb == -2147483648)
	{
		ft_putchar_fd('2', fd);
		*nb = 147483648;
	}
	else
		*nb = *nb * (-1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	highest_power;
	int	num_to_print;

	highest_power = 10;
	if (n < 0)
		ft_print_neg_fd(&n, fd);
	while ((n % highest_power) != n && (highest_power != 1000000000))
		highest_power = highest_power * 10;
	if (n >= 1000000000)
		ft_putchar_fd(48 + n / highest_power, fd);
	while (highest_power != 1)
	{
		num_to_print = 48 + (n % highest_power) / (highest_power / 10);
		ft_putchar_fd(num_to_print, fd);
		highest_power = highest_power / 10;
	}
}
