/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:01:57 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/07 23:23:28 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		split_list(t_file *head, t_file **left, t_file **right)
{
	t_file *slow;
	t_file *fast;
	t_file *mid;

	slow = head;
	fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		mid = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	*left = head;
	*right = mid->next;
	mid->next = NULL;
}

static t_file	*concat_merge(t_file *left, t_file *right,
		int (*compare)(t_file *, t_file *, int), int flags)
{
	t_file *res;

	res = NULL;
	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	if (compare(left, right, flags))
	{
		res = left;
		res->next = concat_merge(left->next, right, compare, flags);
	}
	else
	{
		res = right;
		res->next = concat_merge(left, right->next, compare, flags);
	}
	return (res);
}

void			merge_sort(t_file **head,
		int (*compare)(t_file *, t_file *, int), int flags)
{
	t_file *left;
	t_file *right;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	split_list(*head, &left, &right);
	merge_sort(&left, compare, flags);
	merge_sort(&right, compare, flags);
	*head = concat_merge(left, right, compare, flags);
}
