/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:54:45 by emaune            #+#    #+#             */
/*   Updated: 2017/06/06 17:17:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;
	char			*x;
	char			*y;

	i = 0;
	x = (char *)src;
	y = (char *)dest;
	while (i < n)
	{
		y[i] = x[i];
		if (x[i] == c)
		{
			y[i] = x[i];
			return (&y[i + 1]);
		}
		i++;
	}
	return (NULL);
}
