/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postfix_to_bit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:16:50 by emaune            #+#    #+#             */
/*   Updated: 2017/10/26 12:38:01 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

char	*postfix_to_bit(char *postfix, t_facts *facts)
{
	t_facts	*index;
	int		i;
	char	*ret;
	char	*temp;
	char	*num;
	char	c;

	i = 0;
	ret = ft_strnew(0);
	while (postfix[i])
	{
		if (ft_isupper(postfix[i]))
		{
			index = facts;
			while (index)
			{
				if (postfix[i] == index->fact)
				{
					num = ft_itoa(index->condition);
					temp = ret;
					ret = ft_strjoin(temp, num);
					free(temp);
					free(num);
				}
				index = index->next;
			}
		}
		else
		{
			c = postfix[i + 1];
			postfix[i + 1] = '\0';
			temp = ret;
			ret = ft_strjoin(temp, &postfix[i]);
			free(temp);
			postfix[i + 1] = c;
		}
		i++;
	}
	return (ret);
}
