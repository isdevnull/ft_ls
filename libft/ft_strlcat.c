/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:41:31 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/20 16:46:41 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t bufsiz;

	bufsiz = size;
	if (size < ft_strlen(dst) + 1)
		ft_strncat(dst, src, 0);
	else
	{
		bufsiz = ft_strlen(dst);
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	}
	return (ft_strlen(src) + bufsiz);
}
