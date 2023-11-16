/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:12:53 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/16 22:17:10 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static int	basenbrlen(unsigned long long nbr, int baselen)
{
	int	i;

	i = 0;
	if (0 == nbr)
		return (1);
	while (nbr)
	{
		nbr /= baselen;
		i++;
	}
	return (i);
}

char	*ft_itox_base(unsigned long long nbr, const char *base)
{
	char		*str;
	int			len;

	if (!base || 16 != printf_strlen(base))
		return (0);
	if (!nbr)
		return (printf_strdup("0"));
	len = basenbrlen(nbr, 16);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	while (nbr)
	{
		str[len--] = base[nbr % 16];
		nbr /= 16;
	}
	return (str);
}

size_t	printf_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_ucount_digits(long n)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				digits;
	unsigned long	nb;

	nb = (unsigned long)n;
	digits = ft_ucount_digits(n);
	str = (char *)malloc((digits + 1) * sizeof(char));
	str[digits] = '\0';
	if (0 == nb)
		str[0] = '0';
	while (nb)
	{
		str[--digits] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
