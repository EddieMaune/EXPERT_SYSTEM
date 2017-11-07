/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 09:09:04 by emaune            #+#    #+#             */
/*   Updated: 2017/08/07 14:00:31 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;

	result = (t_list*)malloc(sizeof(*result));
	if (result == NULL)
		return (NULL);
	if (!content)
	{
		result->content = NULL;
		result->content_size = 0;
	}
	else
	{
		result->content = malloc(content_size);
		if (!result->content)
			return (NULL);
		result->content = ft_memcpy(result->content, content, content_size);
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
