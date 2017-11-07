/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:49:43 by emaune            #+#    #+#             */
/*   Updated: 2017/10/17 16:46:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;

	if (!f || !lst)
		return (NULL);
	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	temp = f(lst);
	if (lst->next != NULL)
	{
		temp->next = ft_lstmap(lst->next, f);
	}
	return (temp);
}
