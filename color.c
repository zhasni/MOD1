/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 01:03:57 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/06/03 14:35:52 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int				get_color_ground_bis(int d, float n, int co)
{
	n = d / 70.0;
	if (n > 3.0)
	{
		n = sqrt(n - 3) / 2.0;
		n = MIN(n, 1.0);
		co = interpolate(0xafa06a, 0xfffafa, n);
	}
	else if (n > 1.05)
	{
		n = (n - 1.05) / 1.95;
		co = interpolate(0x748148, 0xafa06a, n);
	}
	else if (n > 0.95)
	{
		n = (n - 0.95) * 10;
		co = interpolate(0x473f25, 0x748148, n);
	}
	else if (n > 0.0)
	{
		n /= 0.95;
		co = interpolate(0xbf9873, 0x473f25, n);
	}
	else
		co = 0xbf9873;
	return (co);
}

int				get_color_ground(int d)
{
	static int	*buf;
	float		n;
	int			co;

	n = 0;
	co = 0;
	if (!buf)
		buf = calloc(40000, sizeof(int));
	if (d >= 40000)
		d = 40000;
	else if (d < 0)
		d = 0;
	if (buf[d] == 0)
		buf[d] = get_color_ground_bis(d, n, co);
	return (buf[d]);
}

int				get_color_water_bis(int d, float n, int co)
{
	n = d / 4.0;
	if (n < 2.0)
	{
		co = interpolate(0xB8DBDE, 0x517C9B, n / 2.0);
	}
	else if (n < 5.0)
	{
		n = (n - 2.0) / 3.0;
		co = interpolate(0x517C9B, 0x282F51, n);
	}
	else if (n < 10.0)
	{
		n = (n - 5.0) / 5.0;
		co = interpolate(0x282F51, 0x141840, n);
	}
	else if (n < 15.0)
	{
		n = (n - 10.0) / 5.0;
		co = interpolate(0x141840, 0x000040, n);
	}
	else
		co = 0x000030;
	return (co);
}

int				get_color_water(int d)
{
	static int	*buf;
	float		n;
	int			co;

	n = 0;
	co = 0;
	if (!buf)
		buf = calloc(40000, sizeof(int));
	if (d >= 40000)
		d = 40000;
	else if (d < 0)
		d = 0;
	if (buf[d] == 0)
	{
		buf[d] = get_color_water_bis(d, n, co);
	}
	return (buf[d]);
}
