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

int mlx(t_env *e)
{
	e->m->mlx_ptr = mlx_init();
	e->m->win_ptr = mlx_new_window(e->m->mlx_ptr,L_WIN,W_WIN,"fdf test");

	e->m->img_ptr = mlx_new_image(e->m->mlx_ptr,L_IMG,W_IMG);
	e->m->data = (int*)mlx_get_data_addr(e->m->img_ptr, &e->m->bpp,
			&e->m->sizeline, &e->m->endian);
	


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


	mlx_put_image_to_window(e->m->mlx_ptr, e->m->win_ptr, e->m->img_ptr,50,50);
	mlx_loop (e->m->mlx_ptr);
	return (0);
}
