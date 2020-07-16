/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:15:04 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 19:16:12 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*cpy1;
	unsigned const char	*cpy2;
	size_t				i;

	cpy1 = dst;
	cpy2 = src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n != 0)
	{
		cpy1[i] = cpy2[i];
		if (cpy2[i] == (unsigned char)c)
		{
			return (&(((char *)dst)[i + 1]));
		}
		i++;
		n--;
	}
	return (NULL);
}
