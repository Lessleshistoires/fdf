/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:19:46 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/16 10:22:09 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int nbrc;

	nbrc = 0;
	while (*str != '\0')
	{
		str++;
		nbrc++;
	}
	return (nbrc);
}
