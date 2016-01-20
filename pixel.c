/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 10:35:33 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/11 10:35:36 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void		put_pixel_to_image(t_env *env, int x, int y, int color)
{
	int		i;

	i = ((env->bpp / 8) * x) + ((env->sline) * y);
	if (i >= 0 && i < SCREEN_Y * env->sline && i > y * env->sline && i <
			(y * env->sline) + ((env->bpp / 8) * SCREEN_X))
	{
		env->str[i] = color;
		env->str[i + 1] = (color) >> 8;
		env->str[i + 2] = (color) >> 16;
	}
}

void		ft_put_pixel_ground(int x, int y, t_env *env, int i)
{
	put_pixel_to_image(env, (y - x) / 2 + SCREEN_X / 2,
				((y + x) / env->view - i) + (SCREEN_Y - (2 * SCREEN_Y
					/ env->view)) / 2,
						get_color_ground(i));
}

void		ft_put_pixel_water(int x, int y, t_env *env, int i)
{
	int		f;

	if (env->rain)
		f = ceil(env->grids->w1[y * LINESIZE + x] / 5.0 - 0.005);
	else
		f = env->grids->w1[y * LINESIZE + x] / 5;
	put_pixel_to_image(env, (y - x) / 2 + SCREEN_X / 2,
					((y + x) / env->view - i) + (SCREEN_Y - (2 *
						SCREEN_Y / env->view)) / 2,
					get_color_water(f));
}
