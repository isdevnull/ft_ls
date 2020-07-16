/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:42:57 by hbespin           #+#    #+#             */
/*   Updated: 2019/10/01 17:41:37 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		int_processing(char *str, int n, int sign)
{
	long int	final_int;
	int			x;

	final_int = 0;
	x = sign;
	while (str[n] <= '9' && str[n] >= '0')
	{
		if (final_int * 10 + (str[n] - '0') < final_int)
			return (sign == 1 ? -1 : 0);
		final_int = final_int * 10 + (str[n] - '0');
		n++;
	}
	return (x * final_int);
}

int				ft_atoi(const char *str)
{
	int sign;
	int n;

	sign = 1;
	n = 0;
	while (str[n] == '\n' || str[n] == '\r' || str[n] == '\t' ||
			str[n] == '\v' || str[n] == '\f' || str[n] == ' ')
		n++;
	if (str[n] == '-')
	{
		sign = -1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	if (str[n] == '0')
		n++;
	return (int_processing((char *)str, n, sign));
}
