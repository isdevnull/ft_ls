/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:59:59 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/07 23:00:13 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				compare_lex(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name) <= 0 ? 1 : 0);
}

static int		compare_size(t_file *a, t_file *b)
{
	if (a->s_stat.st_size == b->s_stat.st_size)
		return (compare_lex(a, b));
	else
		return (a->s_stat.st_size > b->s_stat.st_size);
}

static int		compare_time(t_file *a, t_file *b, int flags)
{
	if (flags & FLAG_LA)
		return (la_comparison(a, b));
	else if (flags & FLAG_FC)
		return (fc_comparison(a, b));
	return (lm_comparison(a, b));
}

int				compare(t_file *a, t_file *b, int flags)
{
	t_file *tmp;

	if (flags & FLAG_REVERSE)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (flags & FLAG_BIG_S)
		return (compare_size(a, b));
	if (flags & FLAG_TIME)
		return (compare_time(a, b, flags));
	return (compare_lex(a, b));
}
