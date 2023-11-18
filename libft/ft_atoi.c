/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:07 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/14 22:27:26 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (' ' == c || '\f' == c || '\n' == c
		|| '\r' == c || '\t' == c || '\v' == c);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if ('+' == str[i] || '-' == str[i])
		if ('-' == str[i++])
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		if (result > (size_t)9223372036854775807 + (sign == -1))
		{
			result = (0 - !(sign == -1));
			break ;
		}
	}
	return ((int )(sign * result));
}
