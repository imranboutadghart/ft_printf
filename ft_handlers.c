/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:05:46 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/08 13:46:35 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	handle_percent(void)
{
	printf_putchar('%');
	return (1);
}

int	handle_char_str(char c, va_list ap)
{
	char	*tmp;

	if ('c' == c)
		printf_putchar((char )(va_arg(ap, int)));
	if ('s' == c)
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
		{
			printf_putstr(printf_memcpy(malloc(7 * sizeof(char)), "(null)", 7));
			return (1);
		}
		tmp = printf_strdup(tmp);
		printf_putstr(tmp);
	}
	return (1);
}

char	*handle_pointer(unsigned long long nbr)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	if (!nbr)
		return (printf_strdup("(nil)"));
	tmp = ft_itox_base((unsigned long) nbr, "0123456789abcdef");
	if (!tmp)
		return (0);
	len = printf_strlen(tmp);
	tmp2 = (char *)malloc(sizeof(char ) * (3 + len));
	if (!tmp2)
		return (0);
	printf_strlcpy(tmp2, "0x", 3);
	printf_strlcat(tmp2, tmp, len + 3);
	free(tmp);
	return (tmp2);
}

int	handle_hex(char c, va_list ap)
{
	char		*str;

	if ('p' == c)
		str = handle_pointer((long)va_arg(ap, void *));
	if ('x' == c)
		str = ft_itox_base((unsigned int)va_arg(ap, int), "0123456789abcdef");
	if ('X' == c)
		str = ft_itox_base((unsigned int)va_arg(ap, int), "0123456789ABCDEF");
	if (!str)
		return (0);
	printf_putstr(str);
	return (1);
}

int	handle_ints(char c, va_list ap)
{
	char	*tmp;

	if ('d' == c || 'i' == c)
		tmp = printf_itoa(va_arg(ap, int));
	if ('u' == c)
		tmp = ft_utoa((unsigned long)va_arg(ap, unsigned int));
	printf_putstr(tmp);
	return (1);
}
