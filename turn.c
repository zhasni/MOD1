/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 09:50:59 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/11 09:51:03 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void			ft_calc_turn_right(t_float *t, int x, int y)
{
	t[x * LINESIZE + (LINEMAX - y)] = t[(LINEMAX - y) * LINESIZE
		+ (LINEMAX - x)];
	t[(LINEMAX - y) * LINESIZE + (LINEMAX - x)] = t[(LINEMAX - x)
		* LINESIZE + y];
	t[(LINEMAX - x) * LINESIZE + y] = t[y * LINESIZE + x];
}

void			ft_calc_turn_left(t_float *t, int x, int y)
{
	t[y * LINESIZE + x] = t[(LINEMAX - x) * LINESIZE + y];
	t[(LINEMAX - x) * LINESIZE + y] = t[(LINEMAX - y) * LINESIZE
		+ (LINEMAX - x)];
	t[(LINEMAX - y) * LINESIZE + (LINEMAX - x)] = t[x * LINESIZE
		+ (LINEMAX - y)];
}

void			turn_table_right(t_float *w, t_float *m, t_env *env)
{
	t_float		tmp_w;
	t_float		tmp_m;
	int			x;
	int			y;

	ft_spin_left(env);
	y = 0;
	while (y < LINESIZE / 2)
	{
		x = 0;
		while (x < LINESIZE / 2)
		{
			tmp_w = w[x * LINESIZE + (LINEMAX - y)];
			ft_calc_turn_right(w, x, y);
			w[y * LINESIZE + x] = tmp_w;
			tmp_m = m[x * LINESIZE + (LINEMAX - y)];
			ft_calc_turn_right(m, x, y);
			m[y * LINESIZE + x] = tmp_m;
			x++;
		}
		y++;
	}
}

void			turn_table_left(t_float *w, t_float *m, t_env *env)
{
	t_float		tmp_w;
	t_float		tmp_m;
	int			x;
	int			y;

	ft_spin_right(env);
	y = 0;
	while (y < LINESIZE / 2)
	{
		x = 0;
		while (x < LINESIZE / 2)
		{
			tmp_w = w[y * LINESIZE + x];
			ft_calc_turn_left(w, x, y);
			w[x * LINESIZE + (LINEMAX - y)] = tmp_w;
			tmp_m = m[y * LINESIZE + x];
			ft_calc_turn_left(m, x, y);
			m[x * LINESIZE + (LINEMAX - y)] = tmp_m;
			x++;
		}
		y++;
	}
}
