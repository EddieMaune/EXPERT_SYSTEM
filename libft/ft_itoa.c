/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:58:26 by emaune            #+#    #+#             */
/*   Updated: 2017/08/04 16:33:13 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while ((n /= 10))
		i++;
	if (n < 10 && n > -10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		k;

	ret = ft_strnew(numlen(n));
	if (!ret)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = numlen(n) - 1;
	k = 0;
	if (n < 0)
	{
		n *= -1;
		k = 1;
	}
	while (i >= 0)
	{
		ret[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	if (k)
		ret[0] = '-';
	return (ret);
}
