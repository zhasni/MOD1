/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 10:19:15 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/11 10:19:18 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

t_float				equalize_threaded_if(t_data *data, int i, int j, t_float o)
{
	t_float			h;

	h = o;
	if (i >= LINESIZE)
	{
		j = i - LINESIZE;
		h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	}
	if (i < MAPLEN - LINESIZE)
	{
		j = i + LINESIZE;
		h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	}
	if ((i + 1) % LINESIZE != 0)
	{
		j = i + 1;
		h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	}
	if (i % LINESIZE != 0)
	{
		j = i - 1;
		h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	}
	return (h);
}

t_float				equalize_threaded_else(t_data *data, int i, int j,
															t_float o)
{
	t_float			h;

	h = o;
	j = i + 1;
	h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	j = i - 1;
	h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	j = i + LINESIZE;
	h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	j = i - LINESIZE;
	h += MIN(((data->w1[j] + data->m[j]) - o) / 4, data->w1[j]);
	return (h);
}

void				*equalize_threaded_rain(t_data *data)
{
	t_float			*w2;
	int				i;
	int				j;
	t_float			h;
	t_float			o;

	w2 = data->w2;
	i = data->thn;
	j = 0;
	while (i < MAPLEN)
	{
		o = data->w1[i] + data->m[i];
		h = o;
		if (i < LINESIZE || i >= MAPLEN - LINESIZE || i % LINESIZE == 0
							|| (i + 1) % LINESIZE == 0)
			h = equalize_threaded_if(data, i, j, o);
		else
			h = equalize_threaded_else(data, i, j, o);
		w2[i] = MAX(h - data->m[i], 0);
		i += THREAD_NUM;
	}
	return (NULL);
}

void				*equalize_threaded(t_data *data)
{
	t_float			*w2;
	int				i;
	int				j;
	t_float			h;
	t_float			o;

	w2 = data->w2;
	i = data->thn;
	j = 0;
	while (i < MAPLEN)
	{
		o = data->w1[i] + data->m[i];
		h = o;
		if (i < LINESIZE || i >= MAPLEN - LINESIZE || i % LINESIZE == 0
							|| (i + 1) % LINESIZE == 0)
			h = equalize_threaded_if(data, i, j, o);
		else
			h = equalize_threaded_else(data, i, j, o);
		w2[i] = ceil(MAX(h - data->m[i], 0));
		i += THREAD_NUM;
	}
	return (NULL);
}

void				call_threads(t_float *w1, t_float *w2, t_float *m, int flag)
{
	pthread_t		t[THREAD_NUM];
	t_data			d[THREAD_NUM];
	int				i;
	int				rc;

	i = -1;
	while (++i < THREAD_NUM)
	{
		d[i].w1 = w1;
		d[i].w2 = w2;
		d[i].thn = i;
		d[i].m = m;
		if (!flag)
			rc = pthread_create(&t[i], NULL,
				(void *(*)(void *))equalize_threaded, &d[i]);
		else
			rc = pthread_create(&t[i], NULL,
				(void *(*)(void *))equalize_threaded_rain, &d[i]);
		if (rc)
			ft_error_rc(-3);
	}
	i = -1;
	while (++i < THREAD_NUM)
		pthread_join(t[i], NULL);
}
