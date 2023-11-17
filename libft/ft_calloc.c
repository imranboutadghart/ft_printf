/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:37:53 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/07 23:01:02 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*addr;
	size_t	mul;
	size_t	max_uint;

	max_uint = 4294967295;
	mul = nmemb * size;
	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > max_uint || size > max_uint || mul > max_uint)
		return (NULL);
	addr = malloc(nmemb * size);
	if (!addr)
		return (0);
	ft_bzero(addr, nmemb * size);
	return (addr);
}
