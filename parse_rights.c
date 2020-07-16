/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:02:16 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/09 00:01:39 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		check_exec(mode_t st_mode, char *buf)
{
	if (buf[3] == 'x' && (st_mode & S_ISUID))
		buf[3] = 's';
	else if (buf[3] == '-' && (st_mode & S_ISUID))
		buf[3] = 'S';
	if (buf[6] == 'x' && (st_mode & S_ISGID))
		buf[6] = 's';
	else if (buf[3] == '-' && (st_mode & S_ISGID))
		buf[6] = 'S';
	if (buf[9] == 'x' && (st_mode & S_ISVTX))
		buf[9] = 't';
	else if (buf[9] == '-' && (st_mode & S_ISVTX))
		buf[9] = 'T';
}

char			*get_rights_template(struct stat s_stat)
{
	char *template;

	if (S_ISLNK(s_stat.st_mode))
		template = "lrwxrwxrwx";
	else if (S_ISBLK(s_stat.st_mode))
		template = "brwxrwxrwx";
	else if (S_ISCHR(s_stat.st_mode))
		template = "crwxrwxrwx";
	else if (S_ISDIR(s_stat.st_mode))
		template = "drwxrwxrwx";
	else if (S_ISSOCK(s_stat.st_mode))
		template = "srwxrwxrwx";
	else if (S_ISFIFO(s_stat.st_mode))
		template = "prwxrwxrwx";
	else
		template = "-rwxrwxrwx";
	return (template);
}

void			parse_rights(mode_t st_mode, char *buf, const char *template)
{
	int i;

	i = 0;
	buf[i] = template[i];
	while (template[++i])
		buf[i] = (st_mode & (1 << (9 - i))) ? template[i] : '-';
	check_exec(st_mode, buf);
	buf[10] = '\0';
	buf[11] = '\0';
}
