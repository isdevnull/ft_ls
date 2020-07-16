/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:01:03 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/07 23:37:19 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*month_day(char *s)
{
	int		start;
	char	s1[7];

	start = 4;
	while (start < 10)
	{
		s1[start - 4] = s[start];
		start++;
	}
	s1[6] = '\0';
	return (ft_strdup(s1));
}

static char		*year(char *s)
{
	char *s1;

	s1 = &s[ft_strlen(s) - 5];
	s1[4] = '\0';
	return (s1);
}

static char		*hour_minute(char *s)
{
	char	*s1;
	size_t	i;

	i = 11;
	if (!(s1 = (char *)malloc(sizeof(char) * 6)))
		return (NULL);
	while (i < 16)
	{
		s1[i - 11] = s[i];
		i++;
	}
	s1[i - 11] = '\0';
	return (s1);
}

void			ft_puttime(time_t t)
{
	time_t		r;
	char		*tmp;
	char		*s;

	time(&r);
	s = ft_strdup(ctime(&t));
	tmp = month_day(s);
	ft_putstr(tmp);
	free(tmp);
	ft_putchar(' ');
	if (r - t > 15778476)
	{
		ft_putchar(' ');
		ft_putstr(year(s));
	}
	else
	{
		tmp = hour_minute(s);
		ft_putstr(tmp);
		free(tmp);
	}
	free(s);
}
