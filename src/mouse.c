/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:59:54 by rdubois           #+#    #+#             */
/*   Updated: 2023/10/05 15:59:55 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	mouse_left(t_data *data)
{
	data->player.angle -= 2;
	data->player.delta_x = sin(data->player.angle * (PI / 180));
	data->player.delta_y = cos(data->player.angle * (PI / 180));
	data->ray.oldplanex = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(2 * (PI / 180)) \
		- data->ray.planey * sin(2 * (PI / 180));
	data->ray.planey = data->ray.oldplanex * sin(2 * (PI / 180)) \
		+ data->ray.planey * cos(2 * (PI / 180));
}

void	mouse_right(t_data *data)
{
	data->player.angle += 2;
	data->player.delta_x = sin(data->player.angle * (PI / 180));
	data->player.delta_y = cos(data->player.angle * (PI / 180));
	data->ray.oldplanex = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(-2 * (PI / 180)) \
		- data->ray.planey * sin(-2 * (PI / 180));
	data->ray.planey = data->ray.oldplanex * sin(-2 * (PI / 180)) \
		+ data->ray.planey * cos(-2 * (PI / 180));
}

int	mouse_event(int x, int y, t_data *data)
{
	if (!data->key.unlock)
	{
		if (x < data->width_win / 2)
			mouse_left(data);
		else if (x > data->width_win / 2)
			mouse_right(data);
		if (x != data->width_win / 2 || y != data->height_win / 2)
			mlx_mouse_move(data->mlx_ptr, data->win_ptr, data->width_win / 2, \
				data->height_win / 2);
	}
	return (0);
}
