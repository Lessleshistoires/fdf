/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:36:23 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 18:20:55 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		env_init(t_env *e)
{
	if (!(e->m = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
	if (!(e->p = (t_point*)malloc(sizeof(t_point))))
		return (0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		return (0);
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	env_init(e);
	e->fd = open(av[1], O_RDONLY);
	if (e->fd == -1)
	{
		ft_putstr("wrong file");
		return (0);
	}
	ft_read(e);
	ft_parse(e->stock);
	e->cn = ft_num_count(e->stock);
	ft_atoti(e);
	mlx(e);
	free(e->stock);
	ft_free_table(e->tab, e->cl);
	free(e->m);
	free(e->p);
	free(e);
	return (0);
}
