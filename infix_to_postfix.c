/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:12:33 by emaune            #+#    #+#             */
/*   Updated: 2017/10/26 12:38:29 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"
#include <stdio.h>

static int			is_and(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

static int			is_or(char c)
{
	if (c == '|')
		return (1);
	return (0);

}

static int		is_xor(char c)
{
	if (c == '^')
		return (1);
	return (0);
}

static int		is_op(char c)
{
	if (is_and(c) || is_or(c) || is_xor(c) || c == '!' || c == '(' || c == ')')
		return (1);
	return (0);
}

static int		check_precedence(char c)
{
	if (c == ')')
		return (5);
	if (c == '!')
		return (4);
	if (is_and(c))
		return (3);
	if (is_or(c))
		return (2);
	if (is_xor(c))
		return (1);
	if (c == '(')
		return (0);
	return (-1);
}

int		stack_len(t_stack *stack)
{
	int		i;
	t_stack *index;

	i = 0;
	index = stack;
	while (index)
	{
		index = index->next;
		i++;
	}
	return (i);
}

t_stack		*push_token_to_stack(char t, t_stack *stack)
{
	t_stack	*index;
	t_stack *temp;

	index = stack;
	if (stack)
	{
		while (index->next)
		{
			index = index->next;
		}
		index->next = (t_stack*)malloc(sizeof(t_stack));
		temp = index;
		index = index->next;
		index->next = NULL;
		index->prev = temp;
		index->token = t;
		return (stack);
	}
	else
	{
		stack = (t_stack*)malloc(sizeof(t_stack));
		stack->next = NULL;
		stack->prev = NULL;
		stack->token = t;
		return (stack);
	}
	return (NULL);
}

t_stack		*pop_token_off_stack(t_stack *stack, char **output)
{
	t_stack *index;
	char	*temp;
	index = stack;
	if (!stack)
		return (NULL);
	while (index->next)
	{
		index = index->next;
	}
	if (index->token != '(')
	{
		temp = *output;
		*output = ft_strjoin(temp, &index->token);
		free (temp);
	}
	if (index == stack)
	{
		//	free(index);
		index = NULL;
		return (NULL);
	}
	else
	{
		index = index->prev;
		free(index->next);
		index->next = NULL;
	}
	return (stack);
}


char			*convert_side(char *side)
{
	t_stack		*stack;
	t_stack		*top;
	char		*output;
	char		*temp;
	char		c;
	int			i;

	stack = NULL;
	i = 0;
	output = ft_strnew(1);
	while (side[i])
	{
		if (stack)
		{
			top = stack;
			while (top->next)
				top = top->next;
		}
		if (is_op(side[i]))
		{
			if (side[i] == '(')
				stack = push_token_to_stack(side[i], stack);
			else if (side[i] == ')')
			{
				while (top)
				{
					top = top->prev;
					stack =	pop_token_off_stack(stack, &output);
									if (top->token == '(')
						break	;
				}
			}
			else if (!stack)
			{
				stack = push_token_to_stack(side[i], stack);
			}
			else if (side[i] == '!')
			{
				stack = push_token_to_stack(side[i], stack);
			}
			else if (check_precedence(side[i]) >= check_precedence(top->token))
			{
				stack = push_token_to_stack(side[i], stack);
			}
			else if (check_precedence(side[i]) <= check_precedence(top->token) && stack_len(stack) >= 1)
			{
				while (check_precedence(side[i]) <= check_precedence(top->token))
				{
					if (top == stack)
					{
						stack =	pop_token_off_stack(stack, &output);
						break	;
					}
					top = top->prev;
					stack =pop_token_off_stack(stack, &output);
				}
				stack = push_token_to_stack(side[i], stack);
			}
		}
		if (ft_isupper(side[i]))
		{
			c = side[i + 1];
			side[i + 1] = '\0';
			temp = output;
			output = ft_strjoin(temp, &side[i]);
			free(temp);
			side[i + 1] = c;
			if (top)
				if (top->token == '!')
				stack = pop_token_off_stack(stack, &output);
		}
		i++;
	}
	while (stack)
	{
		stack = pop_token_off_stack(stack, &output);
	}
	return (output);
}
