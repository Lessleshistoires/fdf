/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:36:23 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/13 14:19:07 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_env	*e;
	
	
	if (ac != 2)
		  return (0);
	
	
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	if (!(e->m = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
	if (!(e->p = (t_point*)malloc(sizeof(t_point))))
		return (0);


	e->fd = open(av[1], O_RDONLY);
	
	ft_read(e);
	ft_putstr(e->stock);
	ft_putstr("read ok");
	ft_putstr("\n");
	
	e->cn = ft_num_count(e->stock);
	ft_atoti(e);
	ft_print_num_tables(e->tab, e->cl, e->cn); 
	ft_putstr("tab ok");
	ft_putstr("\n");

	mlx(e);	
	
	free(e->stock);
	ft_free_table(e->tab, e->cl);
	free(e->m);
	free(e->p);
	free(e);

	return(0); 
}
