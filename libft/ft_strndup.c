/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:31:49 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/30 10:08:25 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;

	cpy = ft_strnew(n);
	if (cpy == NULL)
		return (NULL);
	ft_strncpy(cpy, s1, ft_strnlen(s1, n));
	return (cpy);
}
