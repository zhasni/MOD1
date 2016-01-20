/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 09:51:13 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/11 09:51:18 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void			ft_spin_left(t_env *env)
{
	int			tmp_n;
	int			tmp_s;
	int			tmp_e;
	int			tmp_w;

	tmp_n = env->north;
	tmp_s = env->south;
	tmp_e = env->east;
	tmp_w = env->west;
	env->north = tmp_w;
	env->south = tmp_e;
	env->east = tmp_n;
	env->west = tmp_s;
}

void			ft_spin_right(t_env *env)
{
	int			tmp_n;
	int			tmp_s;
	int			tmp_e;
	int			tmp_w;

	tmp_n = env->north;
	tmp_s = env->south;
	tmp_e = env->east;
	tmp_w = env->west;
	env->north = tmp_e;
	env->south = tmp_w;
	env->east = tmp_s;
	env->west = tmp_n;
}
