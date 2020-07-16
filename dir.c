/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:00:22 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/09 04:26:18 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		recursion_or_die(t_file *head, int flags)
{
	print_insides(head, flags);
	if (flags & FLAG_RECURSION && head->next != NULL)
	{
		traverse_dirs(&(head->next), flags, 1);
	}
	else
		free_list(head->next);
}

void			open_and_read_dir(t_file *head, int flags)
{
	DIR				*ds;
	struct dirent	*dp;
	char			*path;
	t_file			*tmp;

	tmp = NULL;
	if ((ds = opendir(head->path)) != NULL)
	{
		while ((dp = readdir(ds)) != NULL)
		{
			path = append_to_path(head->path, dp->d_name);
			if (!(FLAG_ALL & flags) && dp->d_name[0] == '.')
			{
				free(path);
				continue ;
			}
			fill_struct(path, &(tmp));
			tmp->name = ft_strdup(dp->d_name);
			push_front(&(head->next), tmp);
			free(path);
		}
		closedir(ds);
	}
	merge_sort(&(head->next), compare, flags);
	recursion_or_die(head, flags);
}
