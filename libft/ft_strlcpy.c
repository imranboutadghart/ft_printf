/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:39:25 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/10 21:53:16 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//original segfaults when passed NULL
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	i = 0;
	if (src == dst)
		return (ft_strlen(src));
	slen = ft_strlen(src);
	if (!dstsize)
		return (slen);
	while (slen && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
