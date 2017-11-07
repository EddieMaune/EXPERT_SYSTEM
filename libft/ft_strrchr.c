/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 03:47:28 by emaune            #+#    #+#             */
/*   Updated: 2017/06/09 17:05:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*result;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			result = (char *)&str[i];
			return (result);
		}
		i--;
	}
	return (NULL);
}
