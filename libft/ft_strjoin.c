/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:24 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/06 18:57:33 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dst;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dst = (char *)malloc((i + j + 1) * sizeof(char));
	if (!dst)
		return (0);
	k = -1;
	while (++k < i)
		dst[k] = s1[k];
	k--;
	while (++k < i + j)
		dst[k] = s2[k - i];
	dst[k] = '\0';
	return (dst);
}
