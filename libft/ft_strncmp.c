/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:21:15 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/06 17:34:21 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//expected segfault when passing NULL
//comparison done in unsigned char
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 == s2 || !n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char )s1[i] - (unsigned char )s2[i]);
}
