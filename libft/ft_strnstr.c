/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:54:43 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/12 16:26:07 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;

	if (!small[0])
		return ((char *)big);
	if (!n)
		return (0);
	i = 0;
	while (big[i] && i < n)
	{
		j = 0;
		while (small[j] && big[i + j] && j < n - i && big[i + j] == small[j])
			j++;
		if (!small[j])
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
