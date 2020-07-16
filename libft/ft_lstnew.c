/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:44:40 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/30 10:55:36 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	if (!(link = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	link->content = NULL;
	link->next = NULL;
	link->content_size = 0;
	if (content != NULL)
	{
		if (!(link->content = ft_memalloc(content_size)))
		{
			ft_memdel((void *)link);
			return (NULL);
		}
		ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	return (link);
}
