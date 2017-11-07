/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_facts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:40:16 by emaune            #+#    #+#             */
/*   Updated: 2017/11/06 13:28:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

t_facts			*init_facts(t_input *input_head)
{
	t_input		*index;
	t_facts		*head;
	t_facts		*facts;
	t_facts		*temp;
	int			i;
	int			k;
	int			x;
	int			alpha[255];

	index = input_head;
	facts = (t_facts*)malloc(sizeof(t_facts));
	head = facts;
	facts->prev = NULL;
	k = 0;
	x = 0;
	while (k < 255)
	{
		alpha[k] = 0;
		k++;
	}
	while (index)
	{
		if (index->rule)
		{
			i = 0;
			while (index->rule[i])
			{
				if (is_fact(index->rule[i]))
				{
					if (*index->rule[i] == '!' && !alpha[*(index->rule[i] + 1)])
						x = 1;
					if (!alpha[*(index->rule[i] + x)])
					{
						if (x == 0 && *index->rule[i] == '!')
						{
							i++;
							continue	;
						}
						facts->fact = *(index->rule[i] + x);
						temp = facts;
						facts->condition = 0;
						facts->known = 0;
						facts->next = (t_facts*)malloc(sizeof(t_facts));
						facts = facts->next;
						facts->prev = temp;
						alpha[*index->rule[i]] = 1;
						x = 0;
					}
				}
				i++;
			}
		}
		index = index->next;
	}
	facts = facts->prev;
	free(facts->next);
	facts->next = NULL;
	return (head);
}
