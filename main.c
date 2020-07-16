/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:19:43 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/08 22:19:44 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			traverse_dirs(t_file **head, int flags, int state)
{
	t_file	*current;
	t_file	*to_free;

	link_pointers(head);
	unlink_pointers(head);
	current = *head;
	while (current != NULL)
	{
		if (current->rights[0] == 'd')
		{
			if (state != 0 && !((ft_strcmp(current->name, ".") == 0) ||
				(ft_strcmp(current->name, "..") == 0)))
				ft_putchar('\n');
			if (!(state == 1 &&
				((ft_strcmp(current->name, ".") == 0) ||
				(ft_strcmp(current->name, "..") == 0))))
				open_and_read_dir(current, flags);
			state = 1;
		}
		to_free = current;
		current = current->sub;
		free_node(to_free);
	}
}

static void		traverse_files(t_file **head, t_file **args_dirs, int flags)
{
	t_file	*current;
	t_file	*to_free;

	current = *head;
	print_list(*head, flags);
	while (current != NULL)
	{
		to_free = current;
		current = current->next;
		free_node(to_free);
	}
	if (*args_dirs != NULL)
	{
		if (*head != NULL)
			ft_putchar('\n');
		traverse_dirs(args_dirs, flags, 0);
	}
}

static void		init_root(int flags)
{
	t_file	*tmp;
	t_file	*args_dirs;

	args_dirs = NULL;
	tmp = NULL;
	fill_struct(".", &tmp);
	tmp->name = ft_strdup(".");
	push_front(&args_dirs, tmp);
	traverse_dirs(&args_dirs, flags, 0);
}

static void		init_args(int argc, char **argv, int flags)
{
	t_file	*tmp;
	t_file	*args_dirs;
	t_file	*args_files;

	args_dirs = NULL;
	args_files = NULL;
	tmp = NULL;
	while (argc--)
	{
		fill_struct(*argv, &tmp);
		if (tmp == NULL)
		{
			argv++;
			continue ;
		}
		tmp->name = ft_strdup(*argv++);
		if (tmp->rights[0] == 'd')
			push_front(&args_dirs, tmp);
		else
			push_front(&args_files, tmp);
	}
	merge_sort(&args_dirs, compare, flags);
	merge_sort(&args_files, compare, flags);
	traverse_files(&args_files, &args_dirs, flags);
}

int				main(int argc, char **argv)
{
	int		i;
	int		flags;

	i = parse_args(argc, argv, &flags);
	if (argc == 1)
	{
		init_root(flags);
		return (0);
	}
	argv = argv + i;
	argc = argc - i;
	if (argc == 0)
		init_root(flags);
	else
		init_args(argc, argv, flags);
	return (0);
}
