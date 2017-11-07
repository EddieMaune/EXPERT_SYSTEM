/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:53:57 by emaune            #+#    #+#             */
/*   Updated: 2017/11/07 16:11:01 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_H
# define EXPERT_SYSTEM_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_input
{
	char			*line;
	char			*comment;
	char			**rule;
	char			*initial_facts;
	char			*queries;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

typedef struct		s_fact
{
	char			fact;
	int				condition;
	int				known;
	struct s_fact	*next;
	struct s_fact	*prev;
}					t_facts;

typedef struct		s_stack
{
	char			token;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_goals
{
	char			*rule;
	struct s_goals	*next;
	struct s_goals	*prev;
}					s_goals;

t_input				*store_input(int fd);
int					free_store(t_input	**input_head);
int					check_brackets(char *str);
int					is_fact(char *s);
char				**split_rule(char *facts);
int					check_rule_validity(t_input **input_head);
t_facts				*init_facts(t_input *input_head);
t_facts				*init_known_facts(t_facts *facts, t_input *input_head);
char				*standardize_string(char *s);
char				*get_lhs(char **rule);
char				*get_rhs(char **rule);
char				*convert_side(char *side);
char				*postfix_to_bit(char *postfix, t_facts *facts);
t_facts				*inference_engine(t_input *input_head, t_facts *facts);
int					rpn_calc(char *str);
void				put_hr(char *str, char c);
char				*get_rule(char **rule);
void				draw_logo();

#endif
