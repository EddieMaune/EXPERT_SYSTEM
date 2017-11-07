/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:49:57 by emaune            #+#    #+#             */
/*   Updated: 2017/10/17 16:47:59 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				loop(t_gnl *var, char **line, char **store)
{
	if (ft_strchr(var->nextline, '\n'))
	{
		if (var->nextline[0] == '\n')
		{
			var->c = var->nextline[1];
			var->nextline[1] = 0;
			*line = ft_strdup("");
			var->nextline[1] = var->c;
			var->temp = var->nextline;
			var->nextline++;
			*store = ft_strdup(var->nextline);
			free(var->temp);
			return (7);
		}
		*store = ft_strchr(var->nextline, '\n');
		**store = '\0';
		*store = *store + 1;
		*line = ft_strdup(var->nextline);
		return (7);
	}
	var->temp = var->nextline;
	var->i++;
	var->nextline = ft_strnew((BUFF_SIZE * var->i) + var->extra);
	ft_strcat(var->nextline, var->temp);
	return (0);
}

static int				reading(t_gnl *var, char **line, char **store, int fd)
{
	while ((var->ret = read(fd, var->buffer, BUFF_SIZE)) >= 0)
	{
		if (var->ret == 0 && *var->nextline)
		{
			*line = ft_strdup(var->nextline);
			return (1);
		}
		if (var->ret <= 0)
		{
			return (var->ret);
		}
		var->buffer[var->ret] = 0;
		ft_strcat(var->nextline, var->buffer);
		if (loop(var, line, store) == 7)
			break ;
		free(var->temp);
	}
	return (var->ret <= 0 ? var->ret : 1);
}

static int				emptystore(t_gnl *var, char **line, char **store)
{
	if (ft_strchr(*store, '\n'))
	{
		var->temp = *store;
		if (store[0][0] == '\n')
		{
			var->c = store[0][1];
			store[0][1] = 0;
			*line = ft_strdup("");
			store[0][1] = var->c;
			store[0]++;
			free(var->buffer);
			return (1);
		}
		*store = ft_strchr(*store, '\n');
		store[0][0] = 0;
		store[0]++;
		*line = ft_strdup(var->temp);
		return (1);
	}
	return (0);
}

int						get_next_line(const int fd, char **line)
{
	static t_gnl		var;

	var.fd = fd;
	var.buffer = ft_strnew(BUFF_SIZE);
	var.nextline = ft_strnew(BUFF_SIZE);
	var.extra = 0;
	if (!var.buffer || !var.nextline)
		return (-1);
	var.i = 1;
	if (!var.buffer)
		return (-1);
	if (var.store)
	{
		if (emptystore(&var, line, &var.store) == 1)
			return (1);
		free(var.nextline);
		var.extra = ft_strlen(var.store);
		var.nextline = ft_strnew(BUFF_SIZE + var.extra);
		ft_strcat(var.nextline, var.store);
		var.store = NULL;
	}
	return (reading(&var, line, &var.store, var.fd));
}
