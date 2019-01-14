/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:18:42 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/11 13:39:40 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_table(int **tab, int cl)
{
	int i;

	i = 0;
	while (i < cl)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
