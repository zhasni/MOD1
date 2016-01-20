/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 19:51:45 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/05/26 19:52:16 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

char		*ft_clean(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			str[i] = '0';
		else if (str[i] == ')')
			str[i] = '\0';
		i++;
	}
	return (str);
}

t_point		ft_get_point(char *src)
{
	char	**tmp;
	t_point	point;

	tmp = ft_strsplit(src, ',');
	if (tmp[0] && tmp[1] && tmp[2])
	{
		point.x = atof(tmp[0]);
		point.y = atof(tmp[1]);
		point.z = atof(tmp[2]);
		if (dist_to_side(point.x, point.y) < 20)
			point.is_valid = 0;
		else if (point.z > 30000 || point.z < -30000)
			point.is_valid = 0;
		else
			point.is_valid = 1;
	}
	else
		ft_parse_error(-1);
	return (point);
}

void		ft_get_coord(char *str, t_map *map)
{
	t_point tmp;

	if (str == NULL)
		ft_parse_error(-2);
	else
	{
		str = ft_clean(str);
		tmp = ft_get_point(str);
		map->points[map->len] = tmp;
		map->len++;
	}
	return ;
}

int			ft_check_format(char *src)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
	{
		if (src[i] == '(' || src[i] == ')')
			j++;
		else if (src[i] == ',')
			k++;
		i++;
	}
	if (j == 2 && k == 2)
		return (0);
	else
		return (-1);
}

t_map		ft_parse(int fd)
{
	char	*line;
	char	**tmp;
	int		i;
	t_map	map;

	map.len = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[i])
		{
			if (ft_check_format(tmp[i]) == 0)
				ft_get_coord(tmp[i], &map);
			if (map.len > 50)
			{
				printf("TOO MANY POINT : %d\n", map.len);
				exit(0);
			}
			i++;
		}
	}
	return (map);
}
