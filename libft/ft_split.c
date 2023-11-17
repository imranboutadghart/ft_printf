/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:13 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/07 23:01:51 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	int	flag;
	int	i;
	int	count;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (!flag && s[i] != c)
			flag = ++count;
		if (flag && s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static size_t	count_word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**temp_inicializer(char ***strs, size_t *i, size_t *j, size_t wc)
{
	*strs = (char **)malloc((wc + 1) * sizeof(char *));
	*i = -1;
	*j = 0;
	return (*strs);
}

static char	**myfree(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(strs[i++]);
	free (strs);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_len;
	char	**strs;

	if (!s)
		return (0);
	if (!temp_inicializer(&strs, &i, &j, count_words(s, c)))
		return (0);
	while (++i < count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		if (!s[j])
			break ;
		word_len = count_word_len(&(s[j]), c);
		strs[i] = malloc((word_len + 1) * sizeof(char));
		if (!strs[i])
			return ((char **)myfree(strs, i));
		ft_strlcpy(strs[i], &(s[j]), word_len + 1);
		j += word_len;
	}
	strs[i] = 0;
	return (strs);
}
