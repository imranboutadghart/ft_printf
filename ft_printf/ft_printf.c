/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:12 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/19 21:44:52 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	printf_putchar(char c)
{
	write(1, &c, 1);
	incrementer(0);
}

void	printf_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		printf_putchar(str[i++]);
	free(str);
}

int	handle_special(char c, va_list ap)
{
	if ('%' == c)
		return (handle_percent());
	if (ft_in_str("cspdiuxX", c))
	{
		if ('c' == c || 's' == c)
			return (handle_char_str(c, ap));
		if ('p' == c || 'x' == c || 'X' == c)
			return (handle_hex(c, ap));
		if ('d' == c || 'i' == c || 'u' == c)
			return (handle_ints(c, ap));
	}
	return (0);
}

static int	handle_all(const char *str, int i, va_list ap)
{
	if (!ft_in_str("cspdiuxX%", str[i]))
		return (0);
	return (handle_special(str[i], ap));
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	ap;

	i = (size_t)-1;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] != '%')
		{
			printf_putchar(str[i]);
			continue ;
		}
		i += handle_all(str, i + 1, ap);
	}
	va_end(ap);
	return (incrementer(1));
}
