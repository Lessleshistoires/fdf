/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:28:54 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 18:37:04 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_expose(t_env *e)
{
	e->m->img_ptr = mlx_new_image(e->m->mlx_ptr, L_IMG, W_IMG);
	e->m->data = (int*)mlx_get_data_addr(e->m->img_ptr,
		&e->m->bpp, &e->m->sizeline, &e->m->endian);
	if (e->i == 1)
		ft_pos1(e);
	if (e->i == 2)
		ft_pos2(e);
	mlx_put_image_to_window(e->m->mlx_ptr, e->m->win_ptr,
		e->m->img_ptr, 25, 50);
	mlx_destroy_image(e->m->mlx_ptr, e->m->img_ptr);
	return (0);
}

int	mlx(t_env *e)
{
	e->i = 2;
	e->m->mlx_ptr = mlx_init(e);
	p_init(e);
	e->m->win_ptr = mlx_new_window(e->m->mlx_ptr, L_WIN, W_WIN, "fdf");
	mlx_key_hook(e->m->win_ptr, gere_key, e);
	mlx_expose_hook(e->m->win_ptr, ft_expose, e);
	mlx_loop(e->m->mlx_ptr);
	return (0);
}
