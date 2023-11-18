/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:29:57 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/07 22:59:51 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dest, const void *src, size_t n);

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	while (i)
	{
		i--;
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (src <= dest)
		ft_memrcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
