/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 15:36:25 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/10 15:36:29 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int			expose_hook(t_env *env)
{
	int		nb;

	nb = 0;
	bzero(env->str, SCREEN_Y * env->sline);
	while (nb <= env->h / 100)
	{
		update_water(env->grids, env->h, env);
		nb++;
	}
	if (env->flood)
		if (env->h < 30000)
			env->h++;
	ft_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

void		key_hook_ter(int keycode, t_env *env)
{
	if (keycode == T_6)
		env->east = 1;
	else if (keycode == T_4)
		env->west = 1;
	else if (keycode == T_5)
	{
		env->east = 1;
		env->north = 1;
		env->south = 1;
		env->west = 1;
	}
}

void		key_hook_bis(int keycode, t_env *env)
{
	if (keycode == T_UP)
	{
		if (env->view < 10)
			env->view++;
		else
			env->view *= 2;
		if (env->view > 500)
			env->view = 500;
	}
	else if (keycode == T_DOWN)
	{
		if (env->view < 10)
			env->view--;
		else
			env->view /= 2;
		if (env->view <= 2)
			env->view = 2;
	}
	else if (keycode == T_8)
		env->north = 1;
	else if (keycode == T_2)
		env->south = 1;
	else
		key_hook_ter(keycode, env);
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == T_ESC)
		exit (0);
	else if (keycode == T_PLUS)
	{
		env->h += 50;
	}
	else if (keycode == T_MINUS)
	{
		if (env->rain)
		{
			env->h -= 50;
			if (env->h < 0)
				env->h = 0;
		}
	}
	else if (keycode == T_LEFT)
		turn_table_left(env->grids->w1, env->grids->m, env);
	else if (keycode == T_RIGHT)
		turn_table_right(env->grids->w1, env->grids->m, env);
	else
		key_hook_bis(keycode, env);
	return (0);
}
