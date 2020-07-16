/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:36:34 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/23 19:52:56 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	index;

	if (!s)
		return (NULL);
	substr = ft_strnew(len);
	if (substr == NULL)
		return (NULL);
	index = len;
	while (index-- != 0)
		*substr++ = s[start++];
	*substr = '\0';
	return (substr - len);
}
