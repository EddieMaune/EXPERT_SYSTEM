/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 12:25:24 by emaune            #+#    #+#             */
/*   Updated: 2017/10/18 15:12:57 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		i = ft_strlen(s1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		i = ft_strlen(s2);
	else if (ft_strlen(s1) == ft_strlen(s2))
		i = ft_strlen(s2);
	return (ft_memcmp(s1, s2, i));
}
