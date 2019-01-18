/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:28:54 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 14:50:43 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_draw2(t_env *e)
{
	if (e->p->x + 1 < e->cn)
	{
		e->p->z = e->tab[e->p->y][e->p->x + 1];
		e->p->posx1 = e->p->xd2 + e->p->xx +
			((e->p->x + 1 - e->p->y) * e->p->xx / 2);
		e->p->posy1 = e->p->yd + e->p->yy +
			(e->p->z * e->p->ctey + ((e->p->x + 1 + e->p->y) * e->p->yy) / 2);
		draw_line(e);
	}
	if (e->p->y + 1 < e->cl)
	{
		e->p->z = e->tab[e->p->y + 1][e->p->x];
		e->p->posx1 = e->p->xd2 + e->p->xx + ((e->p->x - (e->p->y +
						1)) * e->p->xx / 2);
		e->p->posy1 = e->p->yd + e->p->yy + (e->p->z * e->p->ctey +
				((e->p->x + e->p->y + 1) * e->p->yy) / 2);
		draw_line(e);
	}
}

int				ft_pos2(t_env *e)
{
	while (e->p->y < e->cl)
	{
		while (e->p->x < e->cn)
		{
			e->p->z = e->tab[e->p->y][e->p->x];
			e->p->posx = e->p->xd2 + e->p->xx + ((e->p->x - e->p->y) *
					e->p->xx / 2);
			e->p->posy = e->p->yd + e->p->yy + (e->p->z * e->p->ctey +
					((e->p->x + e->p->y) * e->p->yy) / 2);
			e->p->pos = e->p->posx + e->p->posy * L_IMG;
			ft_draw2(e);
			e->m->data[e->p->pos] = BLUE;
			e->p->x++;
		}
		e->p->x = 0;
		e->p->xd2 = 450;
		e->p->y++;
	}
	e->p->y = 0;
	return (0);
}
