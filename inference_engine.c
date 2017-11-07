/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inference_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:17:47 by emaune            #+#    #+#             */
/*   Updated: 2017/11/07 13:15:51 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"


static int				is_known(t_facts *facts, char q)
{
	t_facts		*index;

	index = facts;
	while (index)
	{
		if (index->fact == q)
		{
			if (index->known)
				return (1);
		}
		index = index->next;
	}
	return (0);
}

static int				is_true(t_facts *facts, char q)
{
	t_facts		*index;

	index = facts;
	while (index)
	{
		if (index->fact == q)
		{
			if (index->condition)
				return (1);
		}
		index = index->next;
	}
	return (0);
}

static int			lhs_known(t_facts *facts, char *side)
{
	int		i;
	t_facts	*index;

	i = 0;
	while (side[i])
	{
		if (ft_isupper(side[i]))
		{
			index = facts;
			while (index)
			{
				if (side[i] == index->fact)
				{
					if (!index->known)
						return (0);
				}
				index = index->next;
			}
		}
		i++;
	}
	return (1);
}

static int			is_listed_fact(t_facts *facts, char q)
{
	t_facts *index;

	index = facts;
	while (index)
	{
		if (q == index->fact)
			return (1);
		index = index->next;
	}
	return (0);

}

char			*put_delimiter(char *str)
{
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = 0;
	result = ft_strnew(ft_strlen(str) + ft_strlen(str));
	while (str[i])
	{
		result[j] = str[i];
		if (str + i != str + ft_strlen(str) - 1)
			result[j + 1] = ' ';
		j += 2;
		i++;
	}
	return (result);
}

int				rhs_has_op(char *str)
{
	if (ft_strchr(str, '|') || ft_strchr(str, '+') || ft_strchr(str, '!') || ft_strchr(str, '^'))
		return (1);
	return (0);
}

t_facts			*update_facts(t_facts **facts, char *side, char q)
{
	char	*bit_pat;
	char	*str;
	t_facts *index;
	int		rhs;
	int		x;
	char	*outp;
	char	*contr;
	char	*rpn;

	rpn = convert_side(side);
	bit_pat = postfix_to_bit(rpn, *facts);
	sleep(1);
	outp = ft_strdup("| Evaluating Rule |");
	ft_putstr("\x1b[36m");
	put_hr(outp, '_');
	ft_putendl(outp);
	put_hr(outp, '_');
	sleep(1);
	ft_putstr("\x1b[0m");
	ft_putstr("\x1b[33m");
	ft_putstr("Rule (LHS):\t");
	ft_putendl(side);
	ft_putstr("\x1b[0m");
	sleep(1);
	ft_putstr("\t= ");
	ft_putendl(rpn);
	sleep(1);
	ft_putstr("\t= ");
	ft_putstr(bit_pat);
	sleep(1);
	str = put_delimiter(bit_pat);
	index = *facts;
	free(bit_pat);
	free(rpn);
	while (index)
	{
		if (index->fact == q)
		{
			x = index->condition;
			index->condition = rpn_calc(str);
			ft_putstr("\n\t= ");
			ft_putnbr(index->condition);
			ft_putchar('\n');
			sleep(2);
			if (index->condition)
			{
				sleep(1);
				ft_putstr("Therefore, ");
				ft_putchar(index->fact);
				ft_putendl(" is TRUE");
				sleep(1);
			}
			else
			{
				ft_putstr("Therefore, ");
				ft_putchar(index->fact);
				ft_putendl(" is FALSE");
			}
			if (index->condition != x && index->known)
			{
				ft_putstr("\x1b[91m");
				contr = ft_strdup("CONTRADICTION DETECTED: ");
				put_hr(contr, '#');
				ft_putstr(contr);
				ft_putchar(q);
				ft_putstr("\n");
				put_hr(contr, '#');
				ft_putstr("\x1b[0m");
			}
			index->known = 1;
			break	;
		}
		index = index->next;
	}
	free(str);
	free(outp);
	return (*facts);
}

static t_facts			*backward_chain(t_input		*input_head, t_facts **facts, char q)
{
	t_facts		*f;
	t_input		*index;
	t_input		*get_q;
	char		*rhs;
	char		*lhs;
	char		*rule;
	int			i;
	int			cert;

	f = *facts;
	index = input_head;
	cert = 1;
	while (index)
	{
		if (index->rule)
		{
			rhs = get_rhs(index->rule);
			lhs = get_lhs(index->rule);
			rule = get_rule(index->rule);
			if (ft_strchr(rhs, q))
			{
				cert = 0;
				i = 0;
				while (lhs[i])
				{
					if (ft_isupper(lhs[i]))
					{
						if (is_known(*facts, lhs[i]))
						{
							i++;
							continue	;
						}
						else
						{
							if (!is_known(*facts, q))
							{
								ft_putstr("\x1b[33;1m");
								ft_putchar(q);
								ft_putstr(" is unknown - Using Rule: ");
								ft_putendl(rule);
								ft_putstr("\x1b[0m");
							}
							sleep(3);
							*facts = backward_chain(input_head, facts, lhs[i]);
							sleep(2);
						}
					}
					i++;
				}
				get_q = input_head;
				if (lhs_known(*facts, lhs))
				while (get_q)
				{
					if (get_q->queries)
					{
						if (!ft_strchr(get_q->queries, q))
						{
							ft_putstr("\e[34;1m");
							ft_putchar('\t');
							ft_putchar(q);
							ft_putstr(" can be solved - all facts on LHS are known\n");
							ft_putstr("\e[0m");
							sleep(1);
							*facts = update_facts(facts, lhs, q);
							if(	is_known(*facts,q))
							{
								ft_putstr("\x1b[32;1;2m");
								printf("%c is known\n", q);
								ft_putstr("\x1b[0m");
							}
						}
						else if (ft_strchr(get_q->queries, q))
						{
							*facts = update_facts(facts, lhs, q);
							sleep(1);
							ft_putstr("\x1b[32;1m");
							if (is_known(*facts, q) && is_true(*facts, q))
								printf("%c is True\n", q);
							else
								printf("%c is False\n", q);
							ft_putstr("\x1b[0m");
						}
						break	;
					}
					get_q = get_q->next;
				}
				free(lhs);
				free(rhs);
				free(rule);
			}
		}
		index = index->next;
	}
	if (cert)
	{
		ft_putstr("\x1b[31m");
		ft_putstr("Uncertain: No rule found to prove ");
		ft_putchar(q);
		ft_putchar('\n');
		ft_putstr("\x1b[0m");
	}
	return (*facts);
}

t_facts			*inference_engine(t_input	*input_head, t_facts *facts)
{
	t_input		*index;
	t_facts		*head;
	t_input		*x;
	char		*queries;
	char		*outp;
	int			i;

	i = 1;
	index = input_head;
	while (index)
	{
		if (index->queries)
		{
			queries = index->queries;
			while (queries[i])
			{
				head = facts;
				while (head)
				{
					if (head->fact == queries[i])
					{
						if (head->known)
						{
							ft_putstr("\e[32;1m");
							ft_putchar(head->fact);
							ft_putstr(" is ");
							if (head->condition)
								ft_putstr("True");
							else
								ft_putstr("False");
							ft_putendl(" - initial/known fact");
							ft_putstr("\x1b[0m");
							sleep(2);
							break	;
						}
						else
						{
							outp = ft_strdup(" is Not an Initial Fact - Looking for Rule to Prove Query");
							ft_putstr("\x1b[35;1m");
							put_hr(outp, '+');
							ft_putstr("| ");
													ft_putchar(queries[i]);
							ft_putendl(outp);
							put_hr(outp, '+');
							sleep(3);
							ft_putstr("\x1b[0m");
							free(outp);
							ft_putchar('\n');
							backward_chain(input_head, &facts, queries[i]);
							if (!is_known(facts, queries[i]))
							printf("\x1b[31m%c cannot be proved", queries[i]);
							break	;
						}
					}
					else if (!is_listed_fact(facts, queries[i]))
					{
						ft_putstr("\x1b[31;1m");
						printf("Uncertain: %c cannot be proved by rule or initial fact\n", queries[i]);
						ft_putstr("\x1b[0m");
						break	;
					}
					head = head->next;
				}
				i++;
			}
			break	;
		}
		index = index->next;
	}
	return (facts);
}
