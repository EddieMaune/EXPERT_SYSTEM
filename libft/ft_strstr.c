/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:01:10 by emaune            #+#    #+#             */
/*   Updated: 2017/10/17 17:34:21 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(char *big, const char *little)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return (big);
	while (big[i] != '\0')
	{
		result = ft_strchr(big + i, little[0]);
		if (result != NULL)
			while (little[j] != '\0')
			{
				if (result[j] == little[j])
					j++;
				else
					break ;
				if (j == ft_strlen(little))
					return (result);
			}
		j = 0;
		i++;
	}
	return (NULL);
}
