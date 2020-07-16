/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:01:19 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/07 23:01:22 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	push_front(t_file **head, t_file *cur)
{
	if (*head == NULL)
	{
		*head = cur;
		return ;
	}
	cur->next = *head;
	*head = cur;
}

void	link_pointers(t_file **head)
{
	t_file *iterator;

	iterator = *head;
	while (iterator->next != NULL)
	{
		iterator->sub = iterator->next;
		iterator = iterator->next;
	}
}

void	unlink_pointers(t_file **head)
{
	t_file *iterator;

	iterator = *head;
	while (iterator->sub != NULL)
	{
		iterator->next = NULL;
		iterator = iterator->sub;
	}
}

size_t	max_list_name(t_file *head)
{
	size_t max;

	max = 0;
	while (head != NULL)
	{
		max = ft_max(max, ft_strlen(head->name));
		head = head->next;
	}
	return (max);
}

int		block_len(t_file *head, blkcnt_t *total)
{
	int mlen;

	mlen = 0;
	while (head != NULL)
	{
		mlen = ft_max(mlen, int_len(head->s_stat.st_blocks));
		*total = *total + head->s_stat.st_blocks;
		head = head->next;
	}
	return (mlen);
}
