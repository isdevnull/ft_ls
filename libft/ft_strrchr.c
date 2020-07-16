/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:05:27 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/30 14:12:10 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*cpy;
	size_t		len;

	cpy = 0;
	len = ft_strlen(s) - 1;
	while (s != NULL && len)
	{
		if (*s == (char)c)
			cpy = s;
		if (*s == '\0')
			break ;
		++s;
	}
	return ((char *)cpy);
}
