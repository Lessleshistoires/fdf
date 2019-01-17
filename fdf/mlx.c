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


int ft_pos1(t_env *e)
{

while(e->p->y < e->cl)
	{
		while (e->p->x < e->cn)
		{	
			e->p->z = e->tab[e->p->y][e->p->x];
			e->p->posx = (e->p->x + e->p->xd + e->p->z * e->p->ctex);
			e->p->posy = (e->p->y + e->p->yd + e->p->z * e->p->ctey);
			e->p->pos = e->p->posx + e->p->posy * L_IMG;
			if (e->p->x + 1 < e->cn)
			{
				e->p->z = e->tab[e->p->y][e->p->x + 1];
				e->p->posx1 = (e->p->x + 1 + e->p->xd + e->p->xx + e->tab[e->p->y][e->p->x + 1] * e->p->ctex);
				e->p->posy1 = (e->p->y + e->p->yd + e->tab[e->p->y][e->p->x + 1] * e->p->ctey);
				draw_line(e, (float)e->p->posx, (float)e->p->posy,
					(float)e->p->posx1, (float)e->p->posy1);
			}
			if (e->p->y + 1 < e->cl)
			{
				e->p->z = e->tab[e->p->y + 1][e->p->x];
				e->p->posx1 = (e->p->x + e->p->xd + e->tab[e->p->y + 1][e->p->x] * e->p->ctex);
				e->p->posy1 = (e->p->y + 1 + e->p->yd + e->p->yy + e->tab[e->p->y + 1][e->p->x] * e->p->ctey);
				draw_line(e, (float)e->p->posx, (float)e->p->posy,
					(float)e->p->posx1, (float)e->p->posy1);
			}
			e->m->data[e->p->pos] = BLUE;	
			e->p->x++;
			e->p->xd += e->p->xx;
		}
		e->p->x = 0;
		e->p->xd = 20;
		e->p->y++;
		e->p->yd += e->p->yy;
	}
	e->p->y = 0;
	return (0);
}

int ft_pos2(t_env *e)
{
	while(e->p->y < e->cl)
	{
		while (e->p->x < e->cn)
		{	
			e->p->z = e->tab[e->p->y][e->p->x];
			e->p->posx = e->p->xd2 + e->p->xx + ((e->p->x - e->p->y) * e->p->xx / 2);
   		 	e->p->posy = e->p->yd + e->p->yy + (e->p->z * e->p->ctey + ((e->p->x + e->p->y) * e->p->yy) / 2);

			e->p->pos = e->p->posx + e->p->posy * L_IMG;
			if (e->p->z == 0)
				e->m->data[e->p->pos] = BLUE;
			else
				e->m->data[e->p->pos] = RED;
			if (e->p->x + 1 < e->cn)
			{
				e->p->z = e->tab[e->p->y][e->p->x + 1];
				e->p->posx1 = e->p->xd2 + e->p->xx + ((e->p->x + 1 - e->p->y) * e->p->xx / 2);
   		 		e->p->posy1 = e->p->yd + e->p->yy + (e->p->z * e->p->ctey + ((e->p->x + 1 + e->p->y) * e->p->yy) / 2);
				draw_line(e, (float)e->p->posx, (float)e->p->posy, (float)e->p->posx1, (float)e->p->posy1);
			}
			
			if (e->p->y + 1 < e->cl)
			{
				e->p->z = e->tab[e->p->y + 1][e->p->x];
				e->p->posx1 = e->p->xd2 + e->p->xx + ((e->p->x - (e->p->y + 1)) * e->p->xx / 2);
   		 		e->p->posy1 = e->p->yd + e->p->yy + (e->p->z * e->p->ctey + ((e->p->x + e->p->y + 1) * e->p->yy) / 2);
				draw_line(e, (float)e->p->posx, (float)e->p->posy, (float)e->p->posx1, (float)e->p->posy1);
			}
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

int ft_init(t_env *e)
{
	if (e->i == 1)
		ft_pos1(e);
	if (e->i == 2)
		ft_pos2(e);
	return (0);
}

int ft_expose(t_env *e)
{

	e->m->img_ptr = mlx_new_image(e->m->mlx_ptr,L_IMG,W_IMG);
	e->m->data = (int*)mlx_get_data_addr(e->m->img_ptr, &e->m->bpp, &e->m->sizeline, &e->m->endian);
	if (e->i == 1)
		ft_pos1(e);
	if (e->i == 2)
		ft_pos2(e);
	mlx_put_image_to_window(e->m->mlx_ptr, e->m->win_ptr, e->m->img_ptr,25,50);
	mlx_destroy_image(e->m->mlx_ptr, e->m->img_ptr);
	return(0);
}

int mlx(t_env *e)
{
	e->i = 2;
	e->m->mlx_ptr = mlx_init(e);
	
	
	p_init(e);
	
	e->m->win_ptr = mlx_new_window(e->m->mlx_ptr,L_WIN ,W_WIN ,"fdf");
	mlx_key_hook(e->m->win_ptr, gere_key, e);
	
	mlx_expose_hook(e->m->win_ptr, ft_expose, e);

	mlx_loop (e->m->mlx_ptr);
	return (0);
}
