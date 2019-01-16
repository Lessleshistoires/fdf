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
		
			e->p->posx = (e->p->x + e->p->xd + e->tab[e->p->y][e->p->x] * e->p->ctex);
			e->p->posy = (e->p->y + e->p->yd + e->tab[e->p->y][e->p->x] * e->p->ctey);
			e->p->pos = e->p->posx + e->p->posy * L_IMG;
			if (e->p->x + 1 < e->cn)
			{
				e->p->posx1 = XX;
				e->p->posy1 = XY;
				draw_line(e, (float)e->p->posx, (float)e->p->posy,
					(float)e->p->posx1, (float)e->p->posy1);
			}
			if (e->p->y + 1 < e->cl)
			{
				e->p->posx1 = YX;
				e->p->posy1 = YY;
				draw_line(e, (float)e->p->posx, (float)e->p->posy,
					(float)e->p->posx1, (float)e->p->posy1);
			}
			e->m->data[e->p->pos] = BLUE;	
			e->p->x++;
			e->p->xd += e->p->xx;
		}
		e->p->x = 0;
		e->p->xd = 50;
		e->p->y++;
		e->p->yd += e->p->yy;
	}
	return (0);
}

int mlx(t_env *e)
{
	

	e->m->mlx_ptr = mlx_init(e);
	e->m->win_ptr = mlx_new_window(e->m->mlx_ptr,L_WIN,W_WIN,"fdf test");
	
	e->m->img_ptr = mlx_new_image(e->m->mlx_ptr,L_IMG,W_IMG);
	e->m->data = (int*)mlx_get_data_addr(e->m->img_ptr, &e->m->bpp,
			&e->m->sizeline, &e->m->endian);

	p_init(e);
	ft_pos1(e);
	/*
	while(e->p->y < e->cl)
	{
		while (e->p->x < e->cn)
		{	
			e->p->posx = (e->p->xd + e->p->x) * e->p->ctex - e->p->ctey * (e->p->y);
			e->p->posy = (e->tab[e->p->y][e->p->x] + e->p->ctex / 2 * e->p->x + e->p->ctey / 2 * (e->p->y + e->p->yd));
			
			//e->p->posx = ((e->p->x - e->p->y) * e->p->xx / 2);
   		 	//e->p->posy = ((e->p->x + e->p->y) * e->p->yy / 2);

			e->p->pos = e->p->posx + e->p->posy * L_IMG;
			
			if (e->p->x < e->cn)
			{
				e->p->posx1 = (( e->p->xd + e->p->xx + e->p->x + 1) * e->p->ctex + e->p->ctey * e->p->y); 
				e->p->posy1 = (e->tab[e->p->y][e->p->x + 1] - e->p->ctex / 2 * (e->p->x + 1) + e->p->ctey / 2 * (e->p->y + e->p->yd));

				draw_line(e, (float)e->p->posx, (float)e->p->posy, (float)e->p->posx1, (float)e->p->posy1);
			}
			
			if (e->p->y + 1 < e->cl)
			{
				e->p->posx1 = ((e->p->xd + e->p->x) * e->p->ctex - e->p->ctey * (e->p->y +1));
				e->p->posy1 = (e->tab[e->p->y + 1][e->p->x] + e->p->ctex / 2 * e->p->x + e->p->ctey / 2 * (e->p->y + 1 + e->p->yd + e->p->yy));

				draw_line(e, (float)e->p->posx, (float)e->p->posy, (float)e->p->posx1, (float)e->p->posy1);
			}
			
			e->m->data[e->p->pos] = BLUE;	
			e->p->x++;
			e->p->xd += e->p->xx;
		}
		e->p->x = 0;
		e->p->xd = 50;
		e->p->y++;
		e->p->yd += e->p->yy;
	}
	*/
	mlx_put_image_to_window(e->m->mlx_ptr, e->m->win_ptr, e->m->img_ptr,25,50);
	mlx_loop (e->m->mlx_ptr);
	return (0);
}
