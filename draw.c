/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 14:34:30 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/10 14:34:38 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int			ft_draw_ter(int x, int y, t_env *env, int *fn)
{
	int		dn;

	dn = 0;
	if (x < SCREEN_X - 1 && y < SCREEN_Y - 1)
	{
		dn = env->grids->m[(y + 1) * LINESIZE + x + 1] / 5;
		*fn = env->grids->w1[(y + 1) * LINESIZE + x + 1] / 5;
	}
	else
	{
		dn = env->grids->m[y * LINESIZE + x] / 5;
		*fn = 1;
	}
	return (dn);
}

void		ft_draw_bis(int x, int y, t_env *env, int *dn)
{
	int		d;
	int		f;
	int		color;
	int		i;
	int		fn;

	color = 0;
	d = 0;
	d = env->grids->m[y * LINESIZE + x] / 5;
	if (env->rain)
		f = ceil(env->grids->w1[y * LINESIZE + x] / 5.0 - 0.005);
	else
		f = env->grids->w1[y * LINESIZE + x] / 5;
	*dn = ft_draw_ter(x, y, env, &fn);
	i = *dn;
	while (i <= d)
		ft_put_pixel_ground(x, y, env, i++);
	if (f)
	{
		i = fn + *dn;
		d += f + 1;
		while (i <= d)
			ft_put_pixel_water(x, y, env, i++);
	}
}

inline void	ft_draw(t_env *env)
{
	int		x;
	int		y;
	int		dn;

	x = 0;
	while (x < SCREEN_X)
	{
		y = 0;
		while (y < SCREEN_Y)
		{
			ft_draw_bis(x, y, env, &dn);
			y++;
		}
		x++;
	}
	return ;
}
