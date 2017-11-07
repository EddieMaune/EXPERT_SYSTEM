/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:56:09 by emaune            #+#    #+#             */
/*   Updated: 2017/06/09 17:11:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char *str;

	str = (char *)malloc(ft_strlen(s1) + 1);
	if (str != NULL)
		ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
