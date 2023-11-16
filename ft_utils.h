/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:51:08 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/08 13:46:35 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		handle_char_str(char c, va_list ap);
int		handle_hex(char c, va_list ap);
int		handle_ints(char c, va_list ap);
int		handle_percent(void);
int		handle_special(char c, va_list ap);
size_t	incrementer(int flush);
void	printf_putchar(char c);
void	printf_putstr(char *str);
char	*ft_itox_base(unsigned long long nbr, const char *base);
size_t	printf_strlen(const char *str);
char	*ft_utoa(unsigned int nbr);
size_t	printf_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	printf_strlcat(char *dest, const char *src, size_t dstsize);
char	*printf_strdup(const char *str);
int		ft_in_str(const char *str, char c);
char	*printf_itoa(int nbr);
void	*printf_memcpy(void *dest, const void *src, size_t n);

#endif //FT_UTILS_H