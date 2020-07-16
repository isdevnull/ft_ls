/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:17:33 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/08 22:17:37 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lm_comparison(t_file *a, t_file *b)
{
	if (a->s_stat.st_mtimespec.tv_sec ==
			b->s_stat.st_mtimespec.tv_sec)
		return (!(compare_lex(a, b)));
	else
		return (a->s_stat.st_mtimespec.tv_sec >
				b->s_stat.st_mtimespec.tv_sec);
}

int		la_comparison(t_file *a, t_file *b)
{
	if (a->s_stat.st_atimespec.tv_sec ==
			b->s_stat.st_atimespec.tv_sec)
		return (!(compare_lex(a, b)));
	else
		return (a->s_stat.st_atimespec.tv_sec >
				b->s_stat.st_atimespec.tv_sec);
}

int		fc_comparison(t_file *a, t_file *b)
{
	if (a->s_stat.st_birthtimespec.tv_sec ==
			b->s_stat.st_birthtimespec.tv_sec)
		return (!(compare_lex(a, b)));
	else
		return (a->s_stat.st_birthtimespec.tv_sec >
				b->s_stat.st_birthtimespec.tv_sec);
}
