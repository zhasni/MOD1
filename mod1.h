/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:41:05 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/06/03 01:05:21 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD1_H
# define MOD1_H

# include <pthread.h>
# include <float.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <time.h>
# include "libft/includes/libft.h"
# include "gnl.h"

# define MIN(a,b)			(((a)<(b))?(a):(b))
# define MAX(a,b)			(((a)>(b))?(a):(b))
# define CLAMP(x,lo,hi)		MIN(hi, MAX(lo,x))
# define ROOF(a, b)			((a + b - 1) / b)
# define ROUND_MULT(a, b)	(ROOF(a, b) * b)

# define LINESIZE			1000
# define LINEMAX	(LINESIZE - 1)
# define MAPLEN				(LINESIZE * LINESIZE)
# define SCREEN_X			1000
# define SCREEN_Y 			1000
# define MAP_WIDTH			20000
# define UPP				(MAP_WIDTH / SCREEN_Y)
# define T_ESC				53
# define T_PLUS				69
# define T_MINUS			78
# define T_UP				126
# define T_DOWN				125
# define T_LEFT				123
# define T_RIGHT			124

# define T_8				91
# define T_6				88
# define T_2				84
# define T_4				86
# define T_5				87

# define THREAD_NUM			8

typedef float				t_float;

typedef struct				s_point
{
	t_float					x;
	t_float					y;
	t_float					z;
	char					is_valid;
}							t_point;

typedef struct				s_rgb
{
	char					b;
	char					g;
	char					r;
	char					a;
}							t_rgb;

typedef union				u_color
{
	int						val;
	t_rgb					rgb;
}							t_color;

typedef struct				s_map
{
	int						len;
	t_point					points[60];
}							t_map;

typedef struct				s_grids
{
	t_float					w1[MAPLEN];
	t_float					w2[MAPLEN];
	t_float					m[MAPLEN];
}							t_grids;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*str;
	int						bpp;
	int						sline;
	int						endian;
	int						h;
	int						view;
	int						flood;
	int						wave;
	int						rain;
	int						snow;
	int						tsunami;
	int						concav;
	int						north;
	int						south;
	int						east;
	int						west;

	t_map					map;
	t_grids					*grids;
}							t_env;

typedef struct				s_data
{
	t_float					*w1;
	t_float					*w2;
	t_float					*m;
	int						thn;
}							t_data;

t_map						ft_parse(int fd);
void						ft_parse_error(int nb);
int							get_height(int x, int y, t_map map, int concav);
t_float						get_height_rain(int x, int y, t_map map,
								int flat_side);
double						dist_to_side(int x, int y);
int							get_color_water(int c);
int							get_color_ground(int c);
int							interpolate(int c1, int c2, float n);
void						update_water(t_grids *grids, int h, t_env *env);
void						ft_draw(t_env *env);
int							expose_hook(t_env *env);
int							key_hook(int keycode, t_env *env);
void						ft_check_opt(char const *opt, t_env *env);
void						ft_usage(void);
void						turn_table_left(t_float *w, t_float *m, t_env *env);
void						turn_table_right(t_float *w, t_float *m,
								t_env *env);
void						ft_init(t_env *env);
void						put_pixel_to_image(t_env *env, int x, int y,
								int color);
void						ft_put_pixel_ground(int x, int y, t_env *env,
								int i);
void						ft_put_pixel_water(int x, int y, t_env *env, int i);
t_float						dist(t_float x1, t_float y1, t_float x2,
								t_float y2);
void						ft_spin_left(t_env *env);
void						ft_spin_right(t_env *env);
void						call_threads(t_float *w1, t_float *w2, t_float *m,
								int flag);
void						set_flood(t_float *w, t_float level);
void						set_wave(t_float *w, t_float level, t_env *env);
void						set_rain(t_float *w, t_float level, int loop);
void						ft_error_rc(int n);

#endif
