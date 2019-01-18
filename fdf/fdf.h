/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 18:34:48 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include "color.h"
# include "keyboard.h"

# define L_WIN 1100
# define W_WIN 800
# define L_IMG 1050
# define W_IMG 700

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			xd;
	int			xd2;
	int			yd;
	int			posx;
	int			posy;
	int			posx1;
	int			posy1;
	int			pos;
	int			xx;
	int			yy;
	float		ctex;
	float		ctey;
	float		acc;
}				t_point;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			sizeline;
	int			endian;
	float		focal;
	float		height;

}				t_mlx;

typedef struct	s_env
{
	int			fd;
	int			cl;
	char		*line;
	char		*tmp;
	char		*stock;
	int			**tab;
	int			ctr;
	int			cn;
	int			x;
	int			x1;
	int			y;
	int			xmin;
	int			ymin;
	int			xmax;
	int			ymax;
	int			ldist;
	int			hdist;
	int			i;
	t_mlx		*m;
	t_point		*p;
}				t_env;
int				ft_read(t_env *e);
int				ft_num_count(char *str);
int				ft_parse(char *str);
int				ft_atoti(t_env *e);
void			ft_print_num_tables(int **tab, int cl, int cn);
void			ft_free_table(int **tab, int cl);
int				mlx(t_env *e);
int				draw_line(t_env *e);
int				p_init(t_env *e);
int				ft_pos1(t_env *e);
int				ft_pos2(t_env *e);
int				ft_expose(t_env *e);
int				gere_key(int key, t_env *e);

#endif
