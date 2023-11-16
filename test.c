/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:40:47 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/08 13:26:13 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{
	printf(" %p %p '\n", 0, 0);
	ft_printf(" %p %p '\n", 0, 0);
}
