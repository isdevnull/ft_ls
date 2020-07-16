/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:58:43 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 22:35:16 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy1;
	const char	*cpy2;
	size_t		i;

	if (!dst && !src && n != 0)
		return (NULL);
	cpy1 = dst;
	cpy2 = src;
	i = 0;
	while (n != 0)
	{
		cpy1[i] = cpy2[i];
		i++;
		n--;
	}
	return (dst);
}
