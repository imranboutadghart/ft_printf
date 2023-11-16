/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:12:53 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/16 23:08:36 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_in_str(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

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

char	*printf_itoa(int n)
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

void	*printf_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
