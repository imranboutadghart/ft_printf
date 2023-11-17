/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:57:55 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/14 22:25:48 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size;
	size_t	i;

	if (!s || !f)
		return ;
	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
