/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trueray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:22:07 by rdubois           #+#    #+#             */
/*   Updated: 2023/10/02 16:22:08 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	trueray4(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.sidedistx - data->ray.deltadistx);
	else
		data->ray.perpwalldist = (data->ray.sidedisty - data->ray.deltadisty);
	if (data->ray.perpwalldist != 0)
		data->ray.lineheight = (int)(data->height_win / data->ray.perpwalldist);
	else
		data->ray.lineheight = data->height_win;
	data->ray.drawstart = -data->ray.lineheight / 2 + data->height_win / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->ray.lineheight / 2 + data->height_win / 2;
	if (data->ray.drawend >= data->height_win)
		data->ray.drawend = data->height_win - 1;
}

void	trueray3(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] != '0' \
			&& data->map[data->ray.mapy][data->ray.mapx] != 'O')
			data->ray.hit = 1;
	}
}

void	trueray2(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->player.pos_x - data->ray.mapx) \
			* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->player.pos_x) \
			* data->ray.deltadistx;
	}
	if (data->ray.raydiry > 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->player.pos_y - data->ray.mapy) \
			* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->player.pos_y) \
			* data->ray.deltadisty;
	}
}

void	trueray1(t_data *data)
{
	if (data->ray.raydirx == 0)
		data->ray.deltadistx = 1e30;
	else
		data->ray.deltadistx = fabs(1 / data->ray.raydirx);
	if (data->ray.raydiry == 0)
		data->ray.deltadisty = 1e30;
	else
		data->ray.deltadisty = fabs(1 / data->ray.raydiry);
	data->ray.hit = 0;
}

void	trueraycaster(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width_win)
	{
		data->ray.camerax = 2 * i / (double)data->width_win -1;
		data->ray.raydirx = data->player.delta_x + \
			data->ray.planex * data->ray.camerax;
		data->ray.raydiry = data->player.delta_y + \
			data->ray.planey * data->ray.camerax;
		data->ray.mapx = (int)data->player.pos_x;
		data->ray.mapy = (int)data->player.pos_y;
		trueray1(data);
		trueray2(data);
		trueray3(data);
		trueray4(data);
		draw_wall(data, i, data->line_wall);
		i++;
	}
}
