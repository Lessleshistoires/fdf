/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:08:37 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 18:21:51 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_read(t_env *e)
{
	e->cl = 0;
	e->stock = NULL;
	while (get_next_line(e->fd, &e->line) > 0)
	{
		if (e->stock == NULL)
			e->stock = ft_strnew(1);
		e->cl++;
		e->tmp = ft_strjoin(e->stock, e->line);
		free(e->line);
		free(e->stock);
		e->stock = e->tmp;
		e->tmp = ft_strjoin(e->stock, "\n");
		free(e->stock);
		e->stock = e->tmp;
	}
	return (0);
}
