/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:58:41 by emaune            #+#    #+#             */
/*   Updated: 2017/06/09 17:14:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*x;

	i = 0;
	x = &dest[ft_strlen(dest)];
	while (i < n && src[i] != '\0')
	{
		x[i] = src[i];
		i++;
	}
	x[i] = '\0';
	return (dest);
}
