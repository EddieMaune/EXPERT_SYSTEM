/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 02:50:41 by emaune            #+#    #+#             */
/*   Updated: 2017/07/27 17:42:50 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tempdest;
	char	*tempsrc;

	i = 0;
	tempdest = (char *)dest;
	tempsrc = (char *)src;
	if (dest > src)
	{
		while (n > i)
		{
			n--;
			tempdest[n] = tempsrc[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
