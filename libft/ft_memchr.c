/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:35:16 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/06 17:53:23 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n)
		if (((unsigned char *)s)[i++] == (unsigned char)c)
			return (&(((unsigned char *)s)[i - 1]));
	return (0);
}
