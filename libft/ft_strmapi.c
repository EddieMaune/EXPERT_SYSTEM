/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:04:19 by emaune            #+#    #+#             */
/*   Updated: 2017/08/04 17:01:49 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((result = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	if (s && f && result)
	{
		while (s[i])
		{
			result[i] = f(i, s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
