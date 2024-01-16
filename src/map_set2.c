/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:25:47 by gcot              #+#    #+#             */
/*   Updated: 2023/09/19 18:25:56 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_cpy_line(t_data *data, char *tab, char *line)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		tab[x] = line[x];
		x++;
	}
	while (x < data->width - 1)
		tab[x++] = ' ';
	tab[x] = '\0';
}

int	set_map(t_data *data, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 1;
	while (i < data->line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	data->map = malloc(sizeof(*data->map) * data->height + 1);
	while (i < data->height)
	{
		data->map[i] = malloc(sizeof(**data->map) * data->width);
		ft_cpy_line(data, data->map[i], line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

void	set_player(t_player *player, char c, int x, int y)
{
	player->vision = 60;
	if (c == 'N')
		player->angle = 0;
	if (c == 'S')
		player->angle = 180;
	if (c == 'E')
		player->angle = 90;
	if (c == 'W')
		player->angle = -90;
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->opos_x = x;
	player->opos_y = y;
	player->delta_x = cos(player->angle * (PI / 180));
	player->delta_y = sin(player->angle * (PI / 180));
}

int	get_player(t_data *data)
{
	int	y;
	int	x;
	int	bo;

	bo = 0;
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' \
				|| data->map[y][x] == 'W' || data->map[y][x] == 'E')
			{
				if (bo)
					return (ft_error("multiple player"));
				set_player(&data->player, data->map[y][x], x, y);
				set_cam(data);
				bo = 1;
			}
		}
	}
	if (!bo)
		return (ft_error("missing player"));
	return (0);
}

int	ft_dimension(t_data *data, char *line, int fd)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (line)
	{
		y++;
		if (x < ft_strlen(line))
			x = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->height = y;
	data->width = x;
	return (0);
}
