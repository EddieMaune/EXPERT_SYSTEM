/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:26:30 by emaune            #+#    #+#             */
/*   Updated: 2017/11/07 16:13:11 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.h"

void		draw_logo()
{
	int		x;
	int		y;
	int		b;

	y = 0;
	b = 1;
	ft_putstr("\x1b[31m");
	while (y < 3)
	{
		x = 0;
		ft_putstr("\t\t\t\t");
		while (x < 20)
		{
			if ((y == 0 || y == 2) && x == 0)
				ft_putchar('/');
			if ((y == 0 || y == 2)&& x == 19)
				ft_putchar('\\');
			else if (y == 0 || y == 2)
				ft_putchar('*');
			else if (y == 1 && (x > 0 && x < 19))
				ft_putchar(' ');
			if (y == 1 && b == 1)
			{
				ft_putstr("    Expert System");
				b = 0;
			}
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putstr("\x1b[0m");
}
/*
int main(void)
{
	draw_logo();
	return (0);
}*/
