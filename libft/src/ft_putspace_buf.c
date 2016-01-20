/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 21:32:59 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/05/08 21:33:09 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				ft_putspace_buf(size_t len)
{
	size_t			i;

	i = 0;
	while (i++ < len)
		ft_putchar_buf(' ');
}
