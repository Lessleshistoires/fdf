/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/13 14:28:29 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gere_key(int key, t_env *e)
{

	if (key == ESC)
		exit(1);
	if (key == Q)
		e->p->acc += 10;
	if (key == W)
		e->p->acc -= 10;
	if (key == A)
		e->p->xx++;
	if (key == S)
		e->p->xx--;
	if (key == Z)
		e->p->yy++;
	if (key == X)
		e->p->yy--;
	if (key == DOWN_ARROW)
		e->p->yd += 5;
	if (key == UP_ARROW)
		e->p->yd -= 5;
	if (key == RIGHT_ARROW)
		e->p->xd += 5;
	if (key == LEFT_ARROW)
		e->p->xd -= 5;
	if (key == C)
		e->p->ctex += 0.1;
	if (key == V)
		e->p->ctex -= 0.1;
	if (key == B)
		e->p->ctey += 0.1;
	if (key == N)
		e->p->ctey -= 0.1;
	if (key == I)
	{
		e->i = 1;
		e->p->yd = 0;
	}
	if (key == J)
	{
		e->i = 2;
		e->p->yd = 0;
	}
	ft_putnbr(e->p->yd);
	ft_expose(e);
	return (0);
}
