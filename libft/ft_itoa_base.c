/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:40:11 by hbespin           #+#    #+#             */
/*   Updated: 2019/10/01 18:13:26 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_cntsize(int n, int base)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size = 1;
	else if (n < 0)
		size++;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

static char		*ft_itoa_stringforming(unsigned int n, int base,
		int negative, char *ptr)
{
	unsigned int	rem;
	size_t			i;

	i = 0;
	while (n != 0)
	{
		rem = n % base;
		if (rem > 9)
			ptr[i++] = (rem - 10) + 'a';
		else
			ptr[i++] = rem + '0';
		n /= base;
	}
	if (negative == 1)
		ptr[i++] = '-';
	ptr[i] = '\0';
	return (ft_strrev(ptr));
}

static char		*ft_itoa_numprocessing(unsigned int n,
		int base, size_t size, int negative)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = ft_strnew(size);
	if (ptr == NULL)
		return (NULL);
	if (n == 0)
	{
		ptr[i] = '0';
		ptr[i + 1] = '\0';
		return (ptr);
	}
	ptr = ft_itoa_stringforming(n, base, negative, ptr);
	return (ptr);
}

char			*ft_itoa_base(int n, int base)
{
	unsigned int	x;
	char			*num;
	size_t			size;
	int				negative;

	negative = 0;
	if (n < 0)
	{
		x = (unsigned int)(n * -1);
		negative = 1;
	}
	else
		x = (unsigned int)n;
	size = ft_cntsize(n, base);
	num = ft_itoa_numprocessing(x, base, size, negative);
	return (num);
}
