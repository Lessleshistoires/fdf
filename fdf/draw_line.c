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
/*
int	draw_line(t_env *e, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						ft_mov_hor()
					}
				}
			}
		}
	}
}

int ft_mov_hor()
{
	int e;
	
	e = dx * 2;
	dx = e;
	dy = dy * 2;
	while (x1 + 1 != x2)
	{
		data[] = CYAN;
		x1++;
	}
}


*/



int	draw_line(t_env *e, float x1, float y1, float x2, float y2)
{
	float x;
	float y;
	float coef;
	float cte;
	float acc;
	float i;
	i = 0;
	if (x1 == x2)
	{
		i = 0;
		acc = 1000;
		while (i < acc)
		{
			y =  y1 + i * (y2 - y1) / acc;
			x = x1;
			e->m->data[((int)x + (int)y * L_IMG)] = BLUE;
			i++;
		}
	}
	else
	{
		coef = (y1 - y2) / (x1 - x2);
		cte = (float)y1 - coef * x1;
		i = 0;
		acc = 1000;
		while (i <= acc)
		{
			x =  x1 + i * (x2 - x1) / acc;
			y = coef * x + cte;
			e->m->data[((int)x + (int)y * L_IMG)] = CYAN;
			i++;
		}
		
	}
	return(0);
}




