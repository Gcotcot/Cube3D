/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:05:07 by gcot              #+#    #+#             */
/*   Updated: 2023/10/09 17:05:09 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_color(char *line, int i)
{
	while (line[i])
	{
		if (line[i] > 32)
			return (1);
		i++;
	}
	return (0);
}

void	ft_set_floor_cell3(t_data *data, char *line, t_color c)
{
	if (!ft_strchr(line, 'F'))
		data->text.floor = c.r * 256 * 256 + c.g * 256 + c.b;
	else
		data->text.cell = c.r * 256 * 256 + c.g * 256 + c.b;
}

int	get_color(int color, t_color *c, char *line)
{
	while (line[c->i] && line[c->i] >= '0' \
		&& line[c->i] <= '9')
		color = color * 10 + (line[c->i++] - 48);
	return (color);
}

int	ft_set_floor_cell2(t_data *data, char *line, int i)
{
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		data->color.i = 1 + i++;
	data->color.r = get_color(data->color.r, &data->color, line);
	if (i == data->color.i)
		return (1);
	i = data->color.i;
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		data->color.i = ++i;
	data->color.g = get_color(data->color.g, &data->color, line);
	if (i == data->color.i)
		return (1);
	i = data->color.i;
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		data->color.i = ++i;
	data->color.b = get_color(data->color.b, &data->color, line);
	if (i == data->color.i)
		return (1);
	return (0);
}

int	ft_set_floor_cell(t_data *data, char *line)
{
	int	i;

	data->color.r = 0;
	data->color.b = 0;
	data->color.g = 0;
	i = 0;
	if (ft_set_floor_cell2(data, line, i))
		return (ft_error("invalid color"));
	i = data->color.i;
	if (data->color.r > 255 || data->color.g > 255 \
		|| data->color.b > 255 || check_color(line, i))
		return (ft_error("invalid color"));
	ft_set_floor_cell3(data, line, data->color);
	return (0);
}
