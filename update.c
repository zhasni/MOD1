/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:54:53 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/06/10 23:26:35 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void				update_water2(t_grids *grids, int height, t_env *env)
{
	if (env->snow == 1)
	{
		set_rain(grids->w1, height, 50);
		call_threads(grids->w1, grids->w2, grids->m, 0);
		set_rain(grids->w2, height, 50);
		call_threads(grids->w2, grids->w1, grids->m, 0);
	}
}

void				update_water(t_grids *grids, int height, t_env *env)
{
	if (env->flood == 1)
	{
		set_flood(grids->w1, height);
		call_threads(grids->w1, grids->w2, grids->m, 0);
		set_flood(grids->w2, height);
		call_threads(grids->w2, grids->w1, grids->m, 0);
	}
	else if (env->wave == 1)
	{
		set_wave(grids->w1, height, env);
		call_threads(grids->w1, grids->w2, grids->m, 0);
		set_wave(grids->w2, height, env);
		call_threads(grids->w2, grids->w1, grids->m, 0);
	}
	else if (env->rain == 1)
	{
		set_rain(grids->w1, height, 50);
		call_threads(grids->w1, grids->w2, grids->m, 1);
		set_rain(grids->w2, height, 50);
		call_threads(grids->w2, grids->w1, grids->m, 1);
	}
	update_water2(grids, height, env);
}
