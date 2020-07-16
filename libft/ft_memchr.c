/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:16:45 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 21:28:57 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char		*sc;
	size_t					i;

	sc = s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n != 0)
	{
		if (sc[i] == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
		n--;
	}
	return (NULL);
}
