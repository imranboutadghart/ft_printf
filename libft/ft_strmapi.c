/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:33 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/14 22:28:59 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (0);
	size = ft_strlen(s);
	str = (char *)malloc ((size + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
