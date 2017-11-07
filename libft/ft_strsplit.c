/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:34:27 by emaune            #+#    #+#             */
/*   Updated: 2017/10/18 13:19:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			wordlen(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int			words(char *s, char c)
{
	int				i;

	i = 0;
	while (*s)
	{
		s = s + wordlen((char*)s, c);
		while (*s && *s == c)
		{
			if (!*s)
				break ;
			s++;
		}
		i++;
	}
	return (i);
}

static char			**split(char const *s, char c)
{
	char			**ret;
	char			*trim;
	char			*temp;
	int				w;

	if (!s)
		return (NULL);
	trim = ft_strtrim(s);
	if (!trim)
		return (NULL);
	temp = trim;
	while (*trim == c && *trim)
		trim++;
	w = words(trim, c);
	free(temp);
	ret = (char**)malloc(sizeof(char*) * w + 1);
	if (!ret)
		return (NULL);
	ret[w] = NULL;
	return (ret);
}

static char			**mallocsplit(char const *s, char c)
{
	t_split			var;

	var.i = 0;
	if (!s)
		return (NULL);
	var.ret = split(s, c);
	if (!var.ret)
		return (NULL);
	var.trim = ft_strtrim(s);
	if (!var.trim)
		return (NULL);
	var.temp = var.trim;
	while (*var.trim && *var.trim == c)
		var.trim++;
	while (*var.trim)
	{
		var.w = wordlen(var.trim, c);
		var.ret[var.i] = (char*)malloc(sizeof(char) * var.w + 1);
		var.ret[var.i][var.w] = '\0';
		var.trim = var.trim + var.w;
		while (*var.trim && *var.trim == c)
			var.trim++;
		var.i++;
	}
	return (var.ret);
}

char				**ft_strsplit(char const *s, char c)
{
	t_split			var;

	var.i = 0;
	if (!s)
		return (NULL);
	var.ret = mallocsplit(s, c);
	if (!var.ret)
		return (NULL);
	var.trim = ft_strtrim((char*)s);
	if (!var.trim)
		return (NULL);
	while (*var.trim)
	{
		var.j = 0;
		while (*var.trim == c && *var.trim)
			var.trim++;
		while (*var.trim != c && *var.trim)
		{
			var.ret[var.i][var.j] = *var.trim;
			var.trim++;
			var.j++;
		}
		var.i++;
	}
	return (var.ret);
}
