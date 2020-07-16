/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:58:36 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 23:09:28 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = dst;
	s2 = src;
	i = 0;
	if (!dst && !src && len != 0)
		return (NULL);
	if (s1 < s2)
	{
		while (0 < len)
		{
			s1[i] = s2[i];
			i++;
			len--;
		}
	}
	else
	{
		while (0 < len--)
			s1[len] = s2[len];
	}
	return (dst);
}
