/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:32:49 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 23:38:16 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	ptr = ft_strnew(size);
	if (ptr == NULL)
		return (NULL);
	while (*s != '\0')
		*ptr++ = f(*s++);
	*ptr = '\0';
	return (ptr - size);
}
