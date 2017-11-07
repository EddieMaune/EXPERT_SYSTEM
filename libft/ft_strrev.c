/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:46:25 by emaune            #+#    #+#             */
/*   Updated: 2017/06/09 17:08:45 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = ft_strlen(str) - 1;
	j = 0;
	temp = ft_strdup(str);
	while (i >= 0)
	{
		str[j] = temp[i];
		j++;
		i--;
	}
	str[ft_strlen(temp)] = '\0';
	return (str);
}
