/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfd_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 16:24:51 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/05/10 16:31:46 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				ft_setfd_buf(int fd)
{
	t_buffer		*buffer;

	buffer = ft_buf(NULL, 0, 0);
	buffer->fd = fd;
}
