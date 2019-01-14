/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/13 14:28:29 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_env *e, int x1, int y1, int x2, int y2)
{
	int x;
	y2 = 0;
	x = x1;
	while (x <= x2)
	{
		
		e->m->data[x1 + y1 * 1000] = CYAN;
		x1++;
		x++;
	}
	return(0);
}
/*
	int x = 0;
	int y = 0;
	int xd = 0;
	int yd = 0;
	while(y < e->cl)
	{
		while (x < (e->cn - 1) * (W_IMG / e->cn))
		{
			e->m->data[(x + (y + yd) * L_IMG)] = GREEN;
			x++;

		}
		yd = yd + L_IMG / (e->cl);
		x = 0;
		y++;
	}
*/