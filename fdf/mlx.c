/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:28:54 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/13 14:28:25 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_dist(t_env *e)
{
	if (e->cl <= 10)
		e->p->yy = 70;
	else if (e->cl >= 10 && e->cl <= 25)
		e->p->yy = 45;
	else if (e->cl >= 25 && e->cl <= 50)
		e->p->yy = 20;
	else if (e->cl >= 50 && e->cl <= 100)
		e->p->yy = 5;
	else if (e->cl >= 100 && e->cl <= 150)
		e->p->yy = 4;
	else
		e->p->yy = 2;
	if (e->cn <= 10)
		e->p->xx = 70;
	else if (e->cn >= 10 && e->cn <= 25)
		e->p->xx = 45;
	else if (e->cn >= 25 && e->cn <= 50)
		e->p->xx = 20;
	else if (e->cn >= 50 && e->cn <= 100)
		e->p->xx = 5;
	else if (e->cn >= 100 && e->cn <= 150)
		e->p->xx = 5;
	else
		e->p->xx = 4;
	return(0);

}

int mlx(t_env *e)
{
	e->m->mlx_ptr = mlx_init();
	e->m->win_ptr = mlx_new_window(e->m->mlx_ptr,L_WIN,W_WIN,"fdf test");

	e->m->img_ptr = mlx_new_image(e->m->mlx_ptr,L_IMG,W_IMG);
	e->m->data = (int*)mlx_get_data_addr(e->m->img_ptr, &e->m->bpp,
			&e->m->sizeline, &e->m->endian);
	
	ft_dist(e);
	
	e->p->yd = 50;
	e->p->xd = 20;
	float ctex = 0.7;
	float ctey = 0.9;
	/*
	if (e->cn < 22)
		ctex = 10;
	if (e->cl < 10)
		ctey = 10;
	*/
	e->p->x = 0;
	e->p->y = 0;

	while(e->p->y < e->cl)
	{
		while (e->p->x < e->cn)
		{		
			e->p->posx = (e->p->x + e->p->xd + e->tab[e->p->y][e->p->x] * ctex);
			e->p->posy = (e->p->y + e->p->yd + e->tab[e->p->y][e->p->x] * ctey);
			e->p->pos = e->p->posx + e->p->posy * L_IMG;
			
			if (e->p->x + 1 < e->cn)
				{
					e->p->posx1 = (e->p->x + 1 + e->p->xd + e->p->xx + e->tab[e->p->y][e->p->x + 1] * ctex);

					e->p->posy1 = (e->p->y + e->p->yd + e->tab[e->p->y][e->p->x + 1] * ctey);

					draw_line(e, (float)e->p->posx, (float)e->p->posy, (float)e->p->posx1, (float)e->p->posy1);
				}
			if (e->p->y + 1 < e->cl)
				{
					e->p->posx1 = (e->p->x + e->p->xd + e->tab[e->p->y + 1][e->p->x] * ctex);

					e->p->posy1 = (e->p->y + 1 + e->p->yd + e->p->yy + e->tab[e->p->y + 1][e->p->x] * ctey);

					draw_line(e, (float)e->p->posx, (float)e->p->posy, (float)e->p->posx1, (float)e->p->posy1);
				}
			if (e->tab[e->p->y][e->p->x] == 0)
				e->m->data[e->p->pos] = GREY; 
			else 
				e->m->data[e->p->pos] = WHITE;
			e->p->x++;
			e->p->xd += e->p->xx;
		}
		e->p->x = 0;
		e->p->xd = 20;
		e->p->y++;
		e->p->yd += e->p->yy;

	}
/*
	int x = 0;
	int y = 0;
	int xd = 0;
	int yd = 0;

	x = 0;
	y = 0;
	xd = 250;
	yd = 250;
	while(y < e->cl)
	{
		while (x < e->cn)
		{
			ft_putnbr(e->tab[y][x]);
			if (e->tab[y][x] == 0)
				e->m->data[(x + xd) + ((y + yd) * L_IMG)] = RED;
			else
				e->m->data[(x + xd) + ((y + yd) * L_IMG)] = YELLOW;
			xd = xd + 500 / (e->cn);
			if (xd > 0)
				draw_line(e, xd , yd, xd + 500 / e->cn, yd);
			x++;
		}
		xd = 250;
		yd = yd + 500 / (e->cl);
		x = 0;
		y++;

	}
*/

	mlx_put_image_to_window(e->m->mlx_ptr, e->m->win_ptr, e->m->img_ptr,25,50);
	mlx_loop (e->m->mlx_ptr);
	return (0);
}
