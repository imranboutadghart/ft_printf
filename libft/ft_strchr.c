/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:08:25 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/15 00:18:33 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//expected segfault when passing NULL
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == (unsigned char)c)
			return ((char *)&str[i - 1]);
	if ((char )c == 0)
		return ((char *)&str[i]);
	return (0);
}
