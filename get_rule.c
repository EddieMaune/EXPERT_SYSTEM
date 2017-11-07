/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:07:29 by emaune            #+#    #+#             */
/*   Updated: 2017/11/06 16:18:06 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

char		*get_rule(char **rule)
{
	int		i;
	char	*temp;
	char	*ret;

	i = 0;
	ret = ft_strnew(0);
	while (rule[i])
	{
		temp = ret;
		ret = ft_strjoin(temp, rule[i]);
		free(temp);
		i++;
	}
	return (ret);
}
