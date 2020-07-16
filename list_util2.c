/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:20:07 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/09 00:36:28 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_node(t_file *node)
{
	node->next = NULL;
	node->sub = NULL;
	free(node->name);
	node->name = NULL;
	free(node->path);
	node->path = NULL;
	free(node);
}

void	free_list(t_file *head)
{
	t_file *cur;

	while (head != NULL)
	{
		cur = head;
		head = head->next;
		free_node(cur);
	}
}

char	*append_to_path(char *path, const char *entry)
{
	char *cpy;
	char *head;

	if (!(cpy = (char *)malloc((ft_strlen(path)
						+ ft_strlen(entry) + 2) * sizeof(char))))
		return (NULL);
	head = cpy;
	while (*path)
		*cpy++ = *path++;
	*cpy++ = '/';
	while (*entry)
		*cpy++ = *entry++;
	*cpy = '\0';
	return (head);
}

void	print_insides(t_file *head, int flags)
{
	if (flags & FLAG_RECURSION || flags & FLAG_LONG || head != NULL)
	{
		ft_putstr(head->path);
		ft_putchar(':');
		ft_putchar('\n');
	}
	print_list(head->next, flags);
}

void	fill_struct(char *d_name, t_file **object)
{
	char	*template;

	if (!(*object = (t_file *)malloc(sizeof(t_file))))
		return ;
	if (lstat(d_name, &((*object)->s_stat)) == -1)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(d_name);
		free(*object);
		*object = NULL;
		return ;
	}
	(*object)->path = ft_strdup(d_name);
	template = get_rights_template((*object)->s_stat);
	parse_rights((*object)->s_stat.st_mode, (*object)->rights, template);
	check_any_acl(*object);
	ft_bzero((*object)->xattr_lst, XATTR_SIZE);
	if (((*object)->xattr_len = listxattr(d_name,
			(*object)->xattr_lst, XATTR_SIZE, XATTR_NOFOLLOW)) > 0)
		(*object)->rights[10] = '@';
	(*object)->next = NULL;
	(*object)->sub = NULL;
}
