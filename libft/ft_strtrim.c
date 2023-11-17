/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:38 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/06 19:01:35 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

static size_t	index_not_in_set_from_start(const char *s1, const char *set)
{
	size_t	i;

	i = -1;
	while (s1[++i])
		if (!ft_inset(s1[i], set))
			return (i);
	return (i);
}

static size_t	index_not_in_set_from_end(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	while (--i >= 0)
		if (!ft_inset(s1[i], set))
			return (i);
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dst;

	if (!s1)
		return (0);
	if (!set || !set[0])
		return (ft_strdup(s1));
	start = index_not_in_set_from_start(s1, set);
	end = index_not_in_set_from_end(s1, set);
	if (!s1[start])
		return (ft_strdup(""));
	dst = malloc((end - start + 2) * sizeof(char));
	if (!dst)
		return (0);
	i = 0;
	while (start <= end)
		dst[i++] = s1[start++];
	dst[i] = '\0';
	return (dst);
}
