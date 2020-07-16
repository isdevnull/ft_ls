/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:44:25 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/30 00:34:43 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *crnt;

	if (!lst || !f)
		return (NULL);
	crnt = f(lst);
	if (!crnt)
		return (NULL);
	crnt->next = ft_lstmap(lst->next, f);
	return (crnt);
}
