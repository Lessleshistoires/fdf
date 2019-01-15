/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/13 14:28:29 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/includes/libft.h"
#include "minilibx/mlx.h"
#include <math.h>
#include "color.h"

#define L_WIN 1100
#define W_WIN 1100
#define L_IMG 1000
#define W_IMG 1000

typedef struct 		s_point
{
	int		x;
	int		y;
	int		z;
	int		xd;
	int		yd;
	int		posx;
	int		posy;
	int		posx1;
	int		posy1;
	int		pos;
	int		xx;
	int		yy;
}					t_point;

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		sizeline;
	int		endian;
	float	focal;
	float	height;
	
}					t_mlx;

typedef struct		s_env
{
	int			fd;
	/*ft_read*/
	int			cl;
	char		*line;
	char		*tmp;
	char		*stock;
	/*ft_atoti*/
	int			**tab;
	int			ctr;
	int			cn;
	int			x;
	int			x1;
	int			y;
	int			xmin;
	int 		ymin;
	int			xmax;
	int 		ymax;
	int			ldist;
	int			hdist;
	/*mlx*/
	t_mlx		*m;
	t_point		*p;
}					t_env;


int 	ft_read(t_env *e);
int 	ft_num_count(char *str);
int 	ft_atoti(t_env *e);
void 	ft_print_num_tables(int **tab, int cl, int cn);
void    ft_free_table(int **tab, int cl);
int		mlx(t_env *e);
int		draw_line(t_env *e, float x1, float y1, float x2, float y2);


#endif
