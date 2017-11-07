/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:43:29 by emaune            #+#    #+#             */
/*   Updated: 2017/11/03 13:34:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

static char		*remove_comments(char *str)
{
	char		*s;

	if ((s = ft_strchr(str, '#')))
	{
		s--;
		while (s != str && ft_isspace(*s))
			s--;
		s++;
		*s = '\0';
	}
	return (str);
}

static int		empty_line(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '#')
		return (1);
	return (0);
}

static int		sort_input(t_input *index, int line)
{
	int			is_valid;
	char		*str;

	is_valid = 1;
	if (ft_strchr(index->line, '#'))
	{
		index->comment = ft_strdup(ft_strchr(index->line, '#'));
	}
	else
		index->comment = NULL;
	if (ft_strstr(index->line, "=>") || ft_strstr(index->line, "<=>"))
	{
		if (!check_brackets(index->line))
		{
			ft_putstr("Brackets invalid: line-");
			ft_putnbr(line);
			ft_putchar('\n');
			is_valid = 0;
		}
		str = standardize_string(index->line);
		index->rule = split_rule(remove_comments(str));
		free(str);
	}
	else if (ft_strchr(index->line, '=') && index->line[0] != '=' && !empty_line(index->line))
	{
		ft_putstr("\n\nSyntax Error: line-");
		ft_putnbr(line);
		ft_putstr("\n{\n\t--logical connective invalid--");
		ft_putstr("\n\tExpected: \"<=> or =>\"\n}\n");
		index->rule = NULL;
		is_valid = 0;
	}
	else
		index->rule = NULL;
	if (index->line[0] == '=')
	{
		index->initial_facts = remove_comments(ft_strtrim(index->line));
	}
	else
		index->initial_facts = NULL;
	if (index->line[0] == '?')
	{
		index->queries = remove_comments(ft_strtrim(index->line));
	}
	else
		index->queries = NULL;
	if (!index->comment && !index->rule && !index->initial_facts && !index->queries && ft_strlen(index->line))
	{
		ft_putstr("\n\nSyntax Error: line-");
		ft_putnbr(line);
		ft_putstr("\n{\n\t--Rule Invalid--");
		ft_putstr("\n\tExpected: \"Valid rule has two or more facts delimited by logical connective, i.e \'A => Z\'\"\n}\n");
		index->rule = NULL;
		is_valid = 0;
	}
	return (is_valid);
}

t_input			*store_input(int fd)
{
	t_input		*input_head;
	t_input		*index;
	t_input		*temp;
	char		*line;
	int			ln;
	int			has_error;

	input_head = (t_input*)malloc(sizeof(t_input));
	index = input_head;
	index->prev = NULL;
	ln = 1;
	has_error = 0;
	while (get_next_line(fd, &line) == 1)
	{
		index->line = ft_strdup(line);
		if(!sort_input(index, ln))
			has_error = 1;
		temp = index;
		index->next = (t_input*)malloc(sizeof(t_input));
		index = index->next;
		index->prev = temp;
		free(line);
		ln++;
	}
	index = index->prev;
	free(index->next);
	index->next = NULL;
	if (has_error)
	{
		free_store(&input_head);
		input_head = NULL;
	}
	return (input_head);
}
