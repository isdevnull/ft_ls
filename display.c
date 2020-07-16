/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:18:39 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/08 22:18:42 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		disp_lst(t_file *lst, t_matr col, t_matr maxl, int flags)
{
	int		tmp_col;
	int		tmp_row;
	t_file	*tmp;
	int		i;

	i = col.h;
	while (lst != NULL && i--)
	{
		tmp_col = col.w;
		tmp = lst->next;
		while (lst != NULL && tmp_col--)
		{
			disp_name(lst, flags, maxl.h);
			if (tmp_col)
				ft_putnchar(ft_max(maxl.w - ft_strlen(lst->name), 0), ' ');
			tmp_row = col.h;
			while (lst != NULL && tmp_row--)
				lst = lst->next;
		}
		ft_putnchar(1, '\n');
		lst = tmp;
	}
}

static void		disp_lst_l(t_file *lst, unsigned int *size, int flags)
{
	if (flags & FLAG_S)
	{
		ft_putnchar(ft_max(size[6] - int_len(lst->s_stat.st_blocks), 0), ' ');
		ft_putnbr(lst->s_stat.st_blocks);
		ft_putchar(' ');
	}
	ft_putstr(lst->rights);
	ft_strlen(lst->rights) == 10 ? ft_putnchar(2, ' ') : ft_putchar(' ');
	print_num(lst->s_stat.st_nlink, size, 1);
	print_user_group(getpwuid(lst->s_stat.st_uid)->pw_name, size, 2);
	print_user_group(getgrgid(lst->s_stat.st_gid)->gr_name, size, 3);
	print_num(lst->s_stat.st_size, size, 4);
	if (flags & FLAG_LA)
		ft_puttime(lst->s_stat.st_atimespec.tv_sec);
	else if (flags & FLAG_FC)
		ft_puttime(lst->s_stat.st_birthtimespec.tv_sec);
	else
		ft_puttime(lst->s_stat.st_mtimespec.tv_sec);
	ft_putchar(' ');
	disp_name_l(lst, flags);
}

static void		display(t_file *list, int flags)
{
	t_matr			max;
	t_matr			tab;
	blkcnt_t		total;
	t_file			*tmp;
	struct winsize	ts;

	total = 0;
	max.w = max_list_name(list) + 4;
	max.h = (FLAG_S & flags) ? block_len(list, &total) : 0;
	if (flags & FLAG_S)
	{
		ft_putstr("total ");
		ft_putnbr_ll(total);
		ft_putchar('\n');
	}
	ioctl(0, TIOCGWINSZ, &ts);
	tab.w = ts.ws_col / (max.w + max.h);
	tab.h = 0;
	tmp = list;
	while ((++tab.h) && tmp != NULL)
		tmp = tmp->next;
	if (tab.w == 0)
		tab.w = 1;
	tab.h = (tab.h % tab.w ? 1 : 0) + tab.h / tab.w;
	disp_lst(list, tab, max, flags);
}

static void		display_long(t_file *lst, int flags)
{
	unsigned int	*size;
	blkcnt_t		blocks;
	int				first;

	first = 1;
	if (!(size = (unsigned int *)malloc(sizeof(unsigned int) * 7)))
		return ;
	get_size(lst, size, &blocks);
	while (lst != NULL)
	{
		if (first == 1)
		{
			ft_putstr("total ");
			ft_putnbr_ll(blocks);
			ft_putchar('\n');
			first = 0;
		}
		disp_lst_l(lst, size, flags);
		ft_putchar('\n');
		lst = lst->next;
	}
	free(size);
}

void			print_list(t_file *head, int flags)
{
	if (head == NULL)
		return ;
	if (flags & FLAG_LONG)
		display_long(head, flags);
	else
		display(head, flags);
}
