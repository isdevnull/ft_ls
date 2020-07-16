/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:23:52 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/20 16:49:00 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *cpy;

	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
