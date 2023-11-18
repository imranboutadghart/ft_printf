/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:39:35 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/06 18:45:23 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//original function does not handle NULL input
char	*ft_strdup(const char *str)
{
	size_t	size;
	size_t	i;
	char	*dst;

	size = ft_strlen(str);
	dst = malloc ((size + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = -1;
	while (++i <= size)
		dst[i] = str[i];
	return (dst);
}
