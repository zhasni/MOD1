/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 19:48:13 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/05/26 19:49:12 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void		ft_parse_error(int nb)
{
	ft_putstr("ERROR parsing\n");
	exit(nb);
}

void		ft_error_rc(int n)
{
	perror(NULL);
	exit(n);
}
