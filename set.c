/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 10:33:24 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/11 10:33:28 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void				set_flood(t_float *w, t_float level)
{
	int				i;

	i = 0;
	while (i < LINESIZE)
	{
		w[i] = level;
		w[MAPLEN - LINESIZE + i] = level;
		i++;
	}
	i = LINESIZE;
	while (i < MAPLEN)
	{
		w[i] = level;
		w[i + LINESIZE - 1] = level;
		i += LINESIZE;
	}
}

void				set_wave2(t_float *w, t_float level, t_env *env)
{
	int				i;

	i = 0;
	if (env->south)
	{
		while (i < MAPLEN)
		{
			if (i > MAPLEN - LINESIZE)
				w[i] = level;
			i++;
		}
	}
	i = 0;
	if (env->east)
	{
		while (i < MAPLEN)
		{
			if (i % LINESIZE == 0)
				w[i + 1] = level;
			i++;
		}
	}
}

void				set_wave(t_float *w, t_float level, t_env *env)
{
	int				i;

	i = 0;
	if (env->north)
	{
		while (i < LINESIZE)
		{
			w[i] = level;
			i++;
		}
	}
	i = LINESIZE - 1;
	if (env->west)
	{
		while (i < MAPLEN)
		{
			w[i] = level;
			i += LINESIZE;
		}
	}
	set_wave2(w, level, env);
}

void				set_rain(t_float *w, t_float level, int loop)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (i < loop)
	{
		j = 0;
		while (j == 0 || j > MAPLEN)
			j = (unsigned int)rand();
		w[j] += level / 50;
		i++;
	}
}
