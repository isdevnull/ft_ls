/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_display2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:21:38 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/08 22:21:40 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_num(long long value,
				unsigned int *size, unsigned int num)
{
	if (int_len(value) < size[num])
		ft_output_alloc(value,
				size[num] - int_len(value));
	else
		ft_putnbr_ll(value);
	ft_putchar(' ');
}

void			print_user_group(char *name,
				unsigned int *size, unsigned int num)
{
	ft_padding(name,
			size[num] - ft_strlen(name));
	ft_putnchar(2, ' ');
}

static void		manage_xattr(t_file *list, int flags)
{
	char		*p;
	ssize_t		value_len;

	p = NULL;
	if (list->xattr_len > 0 && flags & FLAG_XATTR)
	{
		p = &(list->xattr_lst[0]);
		while (*p)
		{
			value_len = getxattr(list->path, p,
				NULL, XATTR_SIZE, 0, XATTR_NOFOLLOW);
			if (value_len != -1)
			{
				ft_putchar('\n');
				ft_putchar('\t');
				ft_putstr(p);
				ft_putchar('\t');
				ft_putnbr(value_len);
			}
			p = p + ft_strlen(p) + 1;
		}
	}
}

void			disp_name_l(t_file *list, int flags)
{
	char		tmp[PATH_MAX + 1];

	ft_putstr(list->name);
	if (S_ISLNK(list->s_stat.st_mode))
	{
		ft_bzero(tmp, PATH_MAX + 1);
		ft_putstr(" -> ");
		readlink(list->path, tmp, PATH_MAX);
		ft_putstr(tmp);
	}
	manage_xattr(list, flags);
}

void			check_any_acl(t_file *node)
{
	acl_t		acl;
	acl_entry_t	entry;

	if (!(acl = acl_get_file(node->path, ACL_TYPE_EXTENDED)))
		return ;
	if (acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == 0)
		node->rights[10] = '+';
	if (acl_free(acl) == -1)
		return ;
}
