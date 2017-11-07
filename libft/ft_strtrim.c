/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:51:41 by emaune            #+#    #+#             */
/*   Updated: 2017/10/17 18:08:12 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	loop(t_trim *var, char const *s)
{
	while (s[var->i])
		if (ft_isspace(s[var->i]))
		{
			var->sz++;
			var->i++;
		}
		else
			break ;
}

char		*ft_strtrim(char const *s)
{
	t_trim	var;

	var.sz = 0;
	var.i = 0;
	if (!s)
		return (NULL);
	loop(&var, s);
	if (var.sz == ft_strlen(s))
		return (ft_strnew(0));
	var.i = ft_strlen(s) - 1;
	var.start = var.sz;
	while (var.i > 0)
		if (ft_isspace(s[var.i]))
		{
			var.sz++;
			var.i--;
		}
		else
			break ;
	var.result = ft_strnew(ft_strlen(s) - var.sz);
	if (var.result == NULL)
		return (NULL);
	ft_strncpy(var.result, s + var.start, ft_strlen(s) - var.sz);
	return (var.result);
}
