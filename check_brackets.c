/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brackets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:02:37 by emaune            #+#    #+#             */
/*   Updated: 2017/10/19 13:29:03 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"


static char	open_bracket(char c)
{
	return (c == '(');
}

static char	close_bracket(char c)
{
	return (c == ')');
}

static char	get_match(char c)
{
	if (c == '(')
		 return (')');
	if (c == ')')
		return (')');
	 return (0);
}

static char	*find_brackets(char *str, char look_for)
{
	while (*str)
	{
		if (*str == look_for)
			return (str);
		else if (close_bracket(*str))
			return (NULL);
		else if (open_bracket(*str))
		{
			if ((str = find_brackets(str + 1, get_match(*str))) == NULL)
				return (NULL);
			else
				++str;
		}
		else
			++str;
	}
	return ((*str == look_for) ? str : NULL);
}

int		check_brackets(char *str)
{
	if (find_brackets(str, 0))
		return (1);
	return (0);
}
