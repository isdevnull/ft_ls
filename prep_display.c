/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:02:22 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/08 01:05:51 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_size(t_file *lst, unsigned int *size, blkcnt_t *blocks)
{
	*blocks = 0;
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	size[3] = 0;
	size[4] = 0;
	size[5] = 12;
	size[6] = 0;
	while (lst != NULL)
	{
		size[0] = ft_max(ft_strlen(lst->rights), size[0]);
		size[1] = ft_max(int_len(lst->s_stat.st_nlink), size[1]);
		size[2] = ft_max(ft_strlen(getpwuid(lst->s_stat.st_uid)->pw_name),
				size[2]);
		size[3] = ft_max(ft_strlen(getgrgid(lst->s_stat.st_gid)->gr_name),
				size[3]);
		size[4] = ft_max(int_len(lst->s_stat.st_size), size[4]);
		size[6] = ft_max(int_len(lst->s_stat.st_blocks), size[6]);
		*blocks = *blocks + lst->s_stat.st_blocks;
		lst = lst->next;
	}
}

void	ft_padding(char *s, int n)
{
	char	*s1;
	char	*s2;

	if (!(s1 = (char *)malloc(sizeof(char) * (n + 1 + ft_strlen(s)))))
		return ;
	s2 = s1;
	while (n--)
		*s1++ = ' ';
	*s1 = '\0';
	ft_strcat(s2, s);
	ft_putstr(s2);
	free(s2);
}

void	disp_name(t_file *node, int flags, int h)
{
	flags = flags + 1;
	if (h != 0)
	{
		ft_putnchar(ft_max(h - int_len(node->s_stat.st_blocks), 0), ' ');
		ft_putnbr_ll(node->s_stat.st_blocks);
		ft_putchar(' ');
	}
	ft_putstr(node->name);
}

void	ft_output_alloc(int x, unsigned int len)
{
	char	*tmp;

	tmp = ft_itoa(x);
	ft_padding(tmp, len);
	free(tmp);
	tmp = NULL;
}
