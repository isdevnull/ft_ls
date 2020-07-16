/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 22:25:42 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/09 22:45:33 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ll_fd(long long n, int fd)
{
	if (n == -(1LL << 63))
		ft_putstr_fd("-9223372036854775808", fd);
	else if (n >= 10)
	{
		ft_putnbr_ll_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 0 && n != -(1LL << 63))
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_ll_fd(-n, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}
