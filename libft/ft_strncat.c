/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:43:40 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/18 19:11:31 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*cpy;

	cpy = s1;
	while (*cpy != '\0')
		cpy++;
	while (*s2 != '\0' && n-- != 0)
		*cpy++ = *s2++;
	*cpy = '\0';
	return (s1);
}