/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 23:13:11 by zhasni            #+#    #+#             */
/*   Updated: 2015/06/10 23:13:16 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GNL_H
# define _GNL_H

# define BUFF_SIZE 1000

typedef struct		s_struct
{
	char			*str;
	int				pos;
	int				max;
}					t_struct;

int					get_next_line(int const fd, char **line);

#endif
