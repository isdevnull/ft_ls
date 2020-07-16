/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:12:19 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 19:18:49 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*s1;
	const char	*s2;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		haystack = ft_strchr(haystack, *needle);
		if (haystack == NULL)
			return (NULL);
		s1 = haystack;
		s2 = needle;
		while (*s2)
		{
			if (*++s2 == '\0')
				return ((char *)haystack);
			else if (*++s1 != *s2)
				break ;
		}
		haystack++;
	}
	return (NULL);
}
