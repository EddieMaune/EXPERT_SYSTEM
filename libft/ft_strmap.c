/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:53:16 by emaune            #+#    #+#             */
/*   Updated: 2017/08/04 17:02:34 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((result = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	if (s && f && result)
	{
		while (s[i])
		{
			result[i] = f(s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
