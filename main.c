/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:49:34 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/06/10 17:50:41 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int				ft_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (-1);
	if (!(env->win = mlx_new_window(env->mlx, SCREEN_X, SCREEN_Y, "MOD_1")))
		return (-1);
	if (!(env->img = mlx_new_image(env->mlx, SCREEN_X, SCREEN_Y)))
		return (-1);
	if (!(env->str = mlx_get_data_addr(env->img, &(env->bpp), &(env->sline),
					&(env->endian))))
		return (-1);
	mlx_hook(env->win, 2, 3, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop_hook(env->mlx, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

void			store_height(t_float *grid, t_map map, int concav, int rain)
{
	int			i;

	i = 0;
	while (i < MAPLEN)
	{
		if (rain)
			grid[i] = get_height_rain((i % LINESIZE) * UPP, (i / LINESIZE)
				* UPP,
			map, concav) / 7;
		else
			grid[i] = get_height((i % LINESIZE) * UPP, (i / LINESIZE) * UPP,
			map, concav) / 7;
		i++;
	}
}

void			ft_launch(const char **av, t_env *env, int fd)
{
	ft_check_opt(av[1], env);
	fd = open(av[2], O_RDONLY);
	if (fd < 0)
	{
		printf("WRONG FILE MAP ! Display Default Map : ON\n");
		env->map.len = 0;
	}
	else
		env->map = ft_parse(fd);
}

int				main(int ac, char const **av)
{
	t_env		env;
	int			fd;

	fd = 0;
	ft_init(&env);
	if (ac == 3)
		ft_launch(av, &env, fd);
	else
	{
		if (av[1] && strcmp(av[1], "--help") == 0)
			ft_usage();
		printf("Wrong format ! type ./mod1 --help\n");
		exit(-1);
	}
	env.grids = calloc(sizeof(t_grids), 1);
	store_height(env.grids->m, env.map, env.concav, env.rain);
	if (ft_mlx(&env) == -1)
		return (-1);
	return (0);
}
