/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:51:57 by emaune            #+#    #+#             */
/*   Updated: 2017/08/07 11:26:19 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;
	t_list *temp;

	new = *alst;
	while (new)
	{
		del(new->content, new->content_size);
		temp = new->next;
		free(new);
		new = NULL;
		new = temp;
		temp = NULL;
	}
	*alst = NULL;
}
