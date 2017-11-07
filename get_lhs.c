/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rhs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:03:26 by emaune            #+#    #+#             */
/*   Updated: 2017/10/20 10:56:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

char	*get_lhs(char **rule)
{
	int		i;
	char	*rhs;
	char	*temp;

	i = 0;
	rhs = ft_strnew(0);
	while (rule[i])
	{
		if (!ft_strcmp(rule[i], "=>") || !ft_strcmp(rule[i], "<=>"))
			break	;
		else
		{
			temp = rhs;
			rhs = ft_strjoin(temp, rule[i]);
			free(temp);
		}
		i++;
	}
	return (rhs);
}
