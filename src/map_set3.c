/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:30:07 by gcot              #+#    #+#             */
/*   Updated: 2023/09/23 15:30:09 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	modif_map(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (map[y][x] <= 32)
				map[y][x] = '1';
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || \
				data->map[y][x] == 'W' || data->map[y][x] == 'E')
				map[y][x] = '0';
			else if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'D')
				return (ft_error("invalid charactere in map"));
			x++;
		}
		y++;
	}
	return (0);
}

int	verif_map2(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 1;
	while (y < data->height - 1)
	{
		x = 1;
		while (x < data->width - 1)
		{
			if (!(map[y][x] <= 32 || map[y][x] == '1'))
			{
				if (map[y - 1][x] <= 32 || map[y + 1][x] <= 32 || \
					map[y][x - 1] <= 32 || map[y][x + 1] <= 32)
					return (ft_error("hole in map"));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	verif_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < data->width)
	{
		if (!(data->map[0][x] <= 32 || data->map[0][x] == '1'))
			return (ft_error("hole in map"));
		if (!(data->map[data->height - 1][x] <= 32 \
			|| data->map[data->height - 1][x] == '1'))
			return (ft_error("hole in map"));
		x++;
	}
	while (y < data->height)
	{
		if (!(data->map[y][0] <= 32 || data->map[y][0] == '1'))
			return (ft_error("hole in map"));
		if (!(data->map[y][data->width - 1] <= 32 \
			|| data->map[y][data->width - 1] == '1'))
			return (ft_error("hole in map"));
		y++;
	}
	return (verif_map2(data, data->map));
}

int	verif_cub(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (i < 4)
		return (ft_error("invalid file"));
	if (file[i] != 'b' || file[i - 1] != 'u' || \
		file[i - 2] != 'c' || file[i - 3] != '.' \
		|| file[i - 4] == '/')
		return (ft_error("invalid file"));
	return (0);
}

void	set_cam(t_data *data)
{
	if (data->player.angle == -90)
	{
		data->ray.dirx = -1;
		data->ray.diry = 0;
	}
	else if (data->player.angle == 0)
	{
		data->ray.dirx = 0;
		data->ray.diry = 1;
	}
	else if (data->player.angle == 90)
	{
		data->ray.dirx = 1;
		data->ray.diry = 0;
	}
	else
	{
		data->ray.dirx = 0;
		data->ray.diry = -1;
	}
	data->ray.planex = data->ray.diry;
	data->ray.planey = -data->ray.dirx;
	mouse_left(data);
	mouse_right(data);
}
