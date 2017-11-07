/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 08:53:29 by emaune            #+#    #+#             */
/*   Updated: 2017/06/06 22:02:33 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char			*tempdest;
	char			*tempsrc;
	unsigned int	i;

	i = 0;
	tempdest = (char *)dest;
	tempsrc = (char *)src;
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (dest);
}
