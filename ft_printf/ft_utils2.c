/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:12:53 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/17 19:52:18 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

size_t	printf_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	slen = printf_strlen(src);
	if (!dstsize || !dst)
		return (slen);
	while (slen && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

static size_t	min(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}

size_t	printf_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (!dst)
		return (printf_strlen(src));
	if (!src)
		return (min(printf_strlen(dst), dstsize));
	slen = printf_strlen(src);
	dlen = printf_strlen(dst);
	if (dstsize <= dlen)
		return (slen + dstsize);
	while (src[i] && dlen + i + 1 < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

char	*printf_strdup(const char *str)
{
	size_t	size;
	size_t	i;
	char	*dst;

	size = printf_strlen(str);
	dst = malloc ((size + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = -1;
	while (++i <= size)
		dst[i] = str[i];
	return (dst);
}

int	incrementer(int flush)
{
	static int	i = 0;
	int			tmp;

	if (flush)
	{
		tmp = i;
		i = 0;
		return (tmp);
	}
	i++;
	return (i);
}
