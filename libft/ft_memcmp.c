/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:16:50 by emaune            #+#    #+#             */
/*   Updated: 2017/07/22 17:18:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	i = 0;
	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	while (i < n)
	{
		if ((unsigned char)x[i] < (unsigned char)y[i])
			return ((unsigned char)x[i] - (unsigned char)y[i]);
		else if ((unsigned char)x[i] > (unsigned char)y[i])
			return ((unsigned char)x[i] - (unsigned char)y[i]);
		i++;
	}
	return (0);
}
