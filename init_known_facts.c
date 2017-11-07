/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_known_facts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 08:54:48 by emaune            #+#    #+#             */
/*   Updated: 2017/10/25 11:06:50 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

t_facts			*init_known_facts(t_facts *facts, t_input *input_head)
{
	t_facts		*index;
	t_input		*x;
	int			i;

	x = input_head;
	i = 0;
	while (x)
	{
		if (x->initial_facts)
		{
			while (x->initial_facts[i])
			{
				if (x->initial_facts[i] != '=')
				{
					index = facts;
					while (index)
					{
						if (x->initial_facts[i] == index->fact)
						{
							index->condition = 1;
							index->known = 1;
							break	;
						}
						index = index->next;
					}
				}
				i++;
			}
			break	;
		}
		x = x->next;
	}
	return (facts);
}
