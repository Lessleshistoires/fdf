/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init.c                                           :+:      :+:    :+:   */
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
/*
	if (e->cl <= 10)
		e->p->yy = 30;
	else if (e->cl > 10 && e->cl <= 20)
		e->p->yy = 15;
	else if (e->cl > 20 && e->cl <= 30)
		e->p->yy = 10;
	else if (e->cl > 30 && e->cl <= 60)
		e->p->yy = 5;
	else if (e->cl > 60 && e->cl <= 120)
		e->p->yy = 3;
	else
		e->p->yy = 1;

	if (e->cn <= 10)
		e->p->xx = 45;
	else if (e->cn > 10 && e->cn <= 20)
		e->p->xx = 25;
	else if (e->cn > 20 && e->cn <= 45)
		e->p->xx = 10;
	else if (e->cn > 45 && e->cn <= 90)
		e->p->xx = 5;
	else if (e->cn > 90 && e->cn <= 180)
		e->p->xx = 3;
	else
		e->p->xx = 2;
*/
	e->p->xx = 15;
	e->p->yy = 15;
	return(0);
}

int p_init(t_env *e)
{
	ft_dist(e);
	e->p->yd = 150;
	e->p->xd = 50;
	e->p->ctex = 1.5;
	e->p->ctey = 1.5;
	e->p->x = 0;
	e->p->y = 0;
	e->p->acc = 1000;
	return (0);
}