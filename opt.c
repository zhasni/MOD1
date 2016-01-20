/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 14:34:48 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/11 09:48:10 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void			ft_usage(void)
{
	printf("Usage ./mod1 -opt -map_file\n\n");
	printf("options available:\n");
	printf("		 -f -> flood mode\n");
	printf("		 -w -> wave mode\n");
	printf("		 -r -> rain mode\n");
	printf("		 -s -> snow mode\n");
	printf("		 -t -> tsunami mode\n");
	printf("		 -c -> concave mode\n");
	printf("\none option only !\n");
	exit(0);
}

void			ft_init(t_env *env)
{
	srand(time(NULL));
	env->h = 100;
	env->view = 3;
	env->flood = 0;
	env->wave = 0;
	env->rain = 0;
	env->snow = 0;
	env->tsunami = 0;
	env->concav = 0;
	env->north = 0;
	env->south = 0;
	env->east = 0;
	env->west = 0;
}

void			ft_check_opt(char const *opt, t_env *env)
{
	if (strcmp(opt, "-f") == 0)
		env->flood = 1;
	else if (strcmp(opt, "-w") == 0)
		env->wave = 1;
	else if (strcmp(opt, "-r") == 0)
		env->rain = 1;
	else if (strcmp(opt, "-s") == 0)
		env->snow = 1;
	else if (strcmp(opt, "-t") == 0)
		env->tsunami = 1;
	else if (strcmp(opt, "-c") == 0)
	{
		env->flood = 1;
		env->concav = 1;
	}
	else if (strcmp(opt, "-h") == 0)
		ft_usage();
	else
	{
		printf("Wrong format options ! type ./mod1 --help\n");
		exit(-2);
	}
	return ;
}
