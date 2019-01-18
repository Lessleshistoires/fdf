/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 15:46:22 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	straight(t_env *e, float i)
{
	float x;
	float y;

	if ((float)e->p->posx == (float)e->p->posx1)
	{
		while (i < e->p->acc)
		{
			y = (float)e->p->posy + i * ((float)e->p->posy1 -
					(float)e->p->posy) / e->p->acc;
			x = (float)e->p->posx;
			e->m->data[((int)x + (int)y * L_IMG)] = RED;
			i++;
		}
	}
}

int				draw_line(t_env *e)
{
	float x;
	float y;
	float coef;
	float cte;
	float i;

	i = 0;
	coef = ((float)e->p->posy - (float)e->p->posy1) / ((float)e->p->posx -
			(float)e->p->posx1);
	cte = (float)(float)e->p->posy - coef * (float)e->p->posx;
	straight(e, i);
	while (i++ <= e->p->acc)
	{
		x = (float)e->p->posx + i * ((float)e->p->posx1 -
				(float)e->p->posx) / e->p->acc;
		y = coef * x + cte;
		if (y != (float)e->p->posy)
			e->m->data[((int)x + (int)y * L_IMG)] = BLUE;
		else
			e->m->data[((int)x + (int)y * L_IMG)] = RED;
	}
	return (0);
}
