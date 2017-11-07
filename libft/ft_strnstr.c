/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:39:46 by emaune            #+#    #+#             */
/*   Updated: 2017/08/07 15:00:29 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		k = i;
		while (little[j] && k < len)
			if (little[j] == big[k])
			{
				j++;
				k++;
			}
			else
				break ;
		if (j == ft_strlen(little))
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
