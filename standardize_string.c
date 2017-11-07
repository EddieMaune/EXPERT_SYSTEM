/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardize_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:58:44 by emaune            #+#    #+#             */
/*   Updated: 2017/10/19 14:48:29 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

char	*standardize_string(char *s)
{
	int		i;
	int		len;
	char	*ret;
	int		j;
	i = 0;
	len = 1;
	while (s[i])
	{
		if (ft_isupper(s[i]))
			len++;
		if (s[i] == '|' || s[i] == '+' || s[i] == '^')
			len++;
		i++;
	}
	len += 2;
	i = 0;
	j = 0;
	ret = ft_strnew(len + ft_strlen(s));
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '<' && s[i] != '=')
		{
			ret[j] = s[i];
			j++;
			ret[j] = ' ';
			j++;
		}
		else if (s[i] == '<' || s[i] == '=')
		{
			ret[j] = s[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
