/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:08:27 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 15:08:56 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	move(int key, t_env *e)
{
	if (key == DOWN_ARROW)
		e->p->yd += 5;
	if (key == UP_ARROW)
	{
		e->p->yd -= 5;
		if (e->p->yd == -10)
			e->p->yd = 0;
	}
	if (key == RIGHT_ARROW)
		e->p->xd *= 1.1;
	if (key == LEFT_ARROW)
		e->p->xd /= 1.1;
}

static	void	coef(int key, t_env *e)
{
	

	if (key == ONE_PAD)
		e->p->ctex += 0.2;
	if (key == TWO_PAD)
		e->p->ctex -= 0.2;
	if (key == FOUR_PAD)
	{
		e->p->ctey += 0.2;
		if (e->p->ctey >= 4)
			e->p->ctey = -1;
	}
	if (key == FIVE_PAD)
	{
		e->p->ctey -= 0.2;
		if (e->p->ctey <= -4)
			e->p->ctey = -1;
	}
		
}

static	void	dist_acc(int key, t_env *e)
{
	if (key == MORE) 
		e->p->acc *= 1.1;
	if (key == LESS)
		e->p->acc /= 1.1;
	if (key == D)
		e->p->xx++;
	if (key == A)
		e->p->xx--;
	if (key == S)
	{
		e->p->yy++;
		if (e->p->yy == 50)
			p_init(e);
	}
	if (key == W)
	{
		e->p->yy--;
		if (e->p->yy == 1)
			p_init(e);
	}
}

static	void	proj(int key, t_env *e)
{
	if (key == O)
	{
		e->i = 1;
		p_init(e);
	}
	if (key == P)
	{
		e->i = 2;
		p_init(e);
	}
	if (key == I)
		p_init(e);
}

int				gere_key(int key, t_env *e)
{
	if (key == ESC)
		exit(1);
	move(key, e);
	coef(key, e);
	dist_acc(key, e);
	proj(key, e);
	ft_expose(e);
	return (0);
}
