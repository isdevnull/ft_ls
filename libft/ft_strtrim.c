/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:50:08 by hbespin           #+#    #+#             */
/*   Updated: 2019/09/29 23:44:01 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	size = (int)ft_strlen(s) - 1;
	while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t')
		size--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		size--;
	}
	if (size < 0)
		size = 0;
	ptr = ft_strnew(size + 1);
	if (ptr == NULL)
		return (NULL);
	j = -1;
	while (++j < size + 1)
		ptr[j] = s[i++];
	ptr[i] = '\0';
	return (ptr);
}
