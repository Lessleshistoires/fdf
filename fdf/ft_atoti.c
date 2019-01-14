/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:38:01 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/13 14:17:54 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_num_count(char *str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while(str[i] != '\n')
	{
		while (str[i] == ' ')
			i++;	
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
				i++;
			x++;
		}
	}
	return (x);
}

static int ft_tab_init(t_env *e)
{
	e->x1 = 0;
	if (!(e->tab = (int**)malloc(sizeof(int*) * e->cl)))
		return (0);
	e->cn = ft_num_count(e->stock);
	while (e->x1 < e->cl)
	{
		if (!(e->tab[e->x1] = (int*)malloc(sizeof(int) * e->cn)))
			return (0);
		e->x1++;
	}
	return (0);
}


int	ft_atoti(t_env *e)
{
	e->ctr = 0;
	e->y = 0;
	e->x = 0;
	ft_tab_init(e);
	while (e->stock[e->ctr])
	{
		e->tab[e->y][e->x] = ft_atoi(&e->stock[e->ctr]);
		e->x++;
		while (e->stock[e->ctr] == '-' || (e->stock[e->ctr] >= '0' &&
					e->stock[e->ctr] <= '9'))
			e->ctr++;
		while (e->stock[e->ctr] == ' ')
			e->ctr++;
		if (e->stock[e->ctr] == '\n')
		{
			e->y++;
			e->x = 0;
			e->ctr++;
		}
	}
	return (0);
}
