/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_store_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 18:17:07 by emaune            #+#    #+#             */
/*   Updated: 2017/10/18 14:46:05 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

static int		free_rule(char	**rule)
{
	int		i;

	i = 0;
	if (rule)
	{
		while (rule[i])
		{
			free(rule[i]);
			i++;
		}
		free(rule);
	}
	return (1);
}

int				free_store(t_input **input_head)
{
	t_input		*head;

	head = *input_head;
	while (head)
	{
		ft_strdel(&head->line);
		ft_strdel(&head->comment);
		free_rule(head->rule);
		ft_strdel(&head->initial_facts);
		ft_strdel(&head->queries);
		head = head->next;
	}
	head = *input_head;
	while (head->next)
	{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	free(head);
	head = NULL;
	*input_head = NULL;
	return (1);
}
