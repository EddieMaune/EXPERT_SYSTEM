/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rule_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 13:44:24 by emaune            #+#    #+#             */
/*   Updated: 2017/10/19 13:55:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

int				check_rule_validity(t_input **input_head)
{
	t_input		*index;
	int			i;
	int			line;
	int			valid;

	index = *input_head;
	line = 1;
	valid = 1;
	while (index)
	{
		if (index->rule)
		{
			i = 0;
			while (index->rule[i])
			{
				if (ft_isalnum(*index->rule[i]) && !ft_strchr(index->rule[i], '='))
					if (!is_fact(index->rule[i]))
					{
						ft_putstr("\nError: line-");
						ft_putnbr(line);
						ft_putstr("\n{\n\t--fact invalid--\n\tContains: \"");
						ft_putstr(index->rule[i]);
						ft_putstr("\"\n\tExpected: Any Uppercase letter\n}");
						valid = 0;
					}
				i++;
			}
		}
		index = index->next;
		line++;
	}
	return (valid);
}
