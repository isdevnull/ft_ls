/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:44:13 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 16:46:07 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *crnt;
	t_list *nxt;

	crnt = *alst;
	while (crnt)
	{
		nxt = crnt->next;
		del(crnt->content, crnt->content_size);
		free(crnt);
		crnt = nxt;
	}
	*alst = NULL;
}
