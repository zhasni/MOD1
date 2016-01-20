/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:43:13 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/06/10 23:22:00 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int				interpolate(int i1, int i2, float n)
{
	int			r;
	int			g;
	int			b;

	r = round(sqrt(((i2 >> 16) * (i2 >> 16) - (i1 >> 16) * (i1 >> 16)) * n +
		(i1 >> 16) * (i1 >> 16)));
	g = round(sqrt(((i2 >> 8 & 0xFF) * (i2 >> 8 & 0xFF) - (i1 >> 8 & 0xFF) *
		(i1 >> 8 & 0xFF)) * n + (i1 >> 8 & 0xFF) * (i1 >> 8 & 0xFF)));
	b = round(sqrt(((i2 & 0xFF) * (i2 & 0xFF) - (i1 & 0xFF) * (i1 & 0xFF)) *
		n + (i1 & 0xFF) * (i1 & 0xFF)));
	return (r << 16 | g << 8 | b);
}

double			dist_to_side(int x, int y)
{
	double		dx;
	double		dy;
	double		v;

	x = (x > 10000) ? x - 10000 : 10000 - x;
	y = (y > 10000) ? y - 10000 : 10000 - y;
	dx = (double)x / 10000;
	dy = (double)y / 10000;
	dx = (dx * dx) * (dx * dx);
	dy = (dy * dy) * (dy * dy);
	v = (1.0 - (dx + dy)) * 10000;
	v = CLAMP(v, 0, 18000);
	return (v);
}

t_float			get_weight(t_float d)
{
	if (!d)
		d = 0.00001;
	return (100000 / (d * d * d));
}

int				get_height(int x, int y, t_map map, int flat_side)
{
	t_point		p;
	t_float		h;
	t_float		w;
	t_float		tw;
	int			i;

	h = 0;
	i = -1;
	tw = 0;
	while (++i < map.len)
	{
		p = map.points[i];
		if (!p.is_valid)
			continue ;
		w = get_weight(dist(p.x, p.y, (t_float)x, (t_float)y));
		tw += w;
		h += p.z * w;
	}
	if (!flat_side)
	{
		w = get_weight(dist_to_side((t_float)x, (t_float)y));
		tw += w;
	}
	h /= tw;
	return (round(h));
}

t_float			get_height_rain(int x, int y, t_map map, int flat_side)
{
	t_point		p;
	t_float		h;
	t_float		w;
	t_float		tw;
	int			i;

	h = 0;
	i = 0;
	tw = 0;
	while (i < map.len)
	{
		p = map.points[i];
		w = get_weight(dist(p.x, p.y, (t_float)x, (t_float)y));
		tw += w;
		h += p.z * w;
		i++;
	}
	if (!flat_side)
	{
		w = get_weight(dist_to_side((t_float)x, (t_float)y));
		tw += w;
	}
	h /= tw;
	return (h);
}
