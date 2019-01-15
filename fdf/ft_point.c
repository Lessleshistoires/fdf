/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/13 14:28:29 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_dist(t_env *e)
{
	if (e->cl <= 10)
		e->p->yd = 25;
	if (e->cl >= 10 && e->cl <= 50)
		e->p->yd = 10;
	if (e->cn <= 10)
		e->p->xd = 25;
	if (e->cn >= 10 && e->cn <= 50)
		e->p->xd = 10;
	return(0);

}

/*
int		ft_place(t_env *e)
{
	e->p->x = 0;
	e->p->y = 0;
	if (e->tab[y][x] == 0)
			e->m->data[(x + xd) + ((y + yd) * L_IMG)] = RED;
	else
			e->m->data[(x + xd)  + ((y + yd) * L_IMG)] = YELLOW;

}
*/
int		ft_point(t_env *e)
{
	int		ft_dist(e);
	float cte1 = 1;
	float cte2 = 0,5
	e->p->x = 0;
	e->p->y = 0;

	while(e->p->y < e->cl)
	{
		while (e->p->x < e->cn)
		{
			ft_putnbr(e->tab[e->p->y][e->p->x]);
			if (e->tab[e->p->y][e->p->x] == 0)
				e->m->data[(e->p->x + e->p->xd) + ((e->p->y + e->p->yd) * L_IMG)] = RED;
			else
				e->m->data[(e->p->x + e->p->xd + e->tab[y][x] * cte1) + ((e->p->y + e->p->yd + e->tab[y][x] * cte2) * L_IMG)] = YELLOW;
			e->p->x++;
		}
		e->p->x = 0;
		e->p->y++;

	}
	return(0);
}