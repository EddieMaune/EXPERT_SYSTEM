/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:32:03 by emaune            #+#    #+#             */
/*   Updated: 2017/10/18 13:58:36 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

static	char	*replace_tab_with_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char		**split_rule(char *facts)
{
	char	**rule;
	
	replace_tab_with_space(facts);
	rule = ft_strsplit(facts, ' ');
	if (!rule)
		return (NULL);
	return (rule);
}
