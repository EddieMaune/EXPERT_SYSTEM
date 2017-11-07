/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:55:52 by emaune            #+#    #+#             */
/*   Updated: 2017/08/07 16:20:30 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	t_lcat	var;

	var.dstlen = ft_strlen(dest);
	var.srclen = ft_strlen(src);
	if (size == 0)
	{
		dest = (char*)src;
		return (ft_strlen(dest));
	}
	else
	{
		var.i = 0;
		while (dest[var.i] && var.i < size)
			var.i++;
		var.dstlen = var.i;
		while (var.i < size - 1 && src[var.i - var.dstlen] != '\0')
		{
			dest[var.i] = src[var.i - var.dstlen];
			var.i++;
		}
		if (var.dstlen < size)
			dest[var.i] = '\0';
	}
	return (ft_strlen(src) + var.dstlen);
}
