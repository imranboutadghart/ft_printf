/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:18:42 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/07 23:02:23 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	long	nb;

	nb = (long)n;
	digits = ft_count_digits(n);
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (!str)
		return (0);
	str[digits] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (0 == nb)
		str[0] = '0';
	while (nb)
	{
		str[--digits] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
