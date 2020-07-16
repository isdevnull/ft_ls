/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:22:58 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 22:39:46 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && len != 0)
	{
		dst[i] = src[i];
		len--;
		i++;
	}
	while (len > 0)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	return (dst);
}
