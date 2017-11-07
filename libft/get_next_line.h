/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:22:10 by emaune            #+#    #+#             */
/*   Updated: 2017/10/17 16:47:23 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 5

# include <stdlib.h>
# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_gnl
{
	int				fd;
	char			*store;
	char			*buffer;
	char			*nextline;
	char			*temp;
	int				ret;
	int				i;
	char			c;
	int				extra;
	struct s_gnl	*nextfd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
