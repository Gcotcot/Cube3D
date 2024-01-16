/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:08:56 by gcot              #+#    #+#             */
/*   Updated: 2023/09/22 17:52:50 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

void	verif_wall(double newx, double newy, t_data *data)
{
	if (data->key.left == true)
		go_left(data, newx, newy);
	else if (data->key.right == true)
		go_right(data, newx, newy);
	else if (data->key.up == true)
		go_up(data, newx, newy);
	else if (data->key.down == true)
		go_down(data, newx, newy);
}

int	moving(t_data *data)
{
	double	newx;
	double	newy;

	newx = 0;
	newy = 0;
	if (data->key.left == true || data->key.right == true)
	{
		newx = data->player.delta_y;
		newy = data->player.delta_x;
	}
	else if (data->key.up == true || data->key.down == true)
	{
		newx = data->player.delta_x;
		newy = data->player.delta_y;
	}
	if (data->key.right_arrow == true)
		mouse_right(data);
	else if (data->key.left_arrow == true)
		mouse_left(data);
	verif_wall(newx, newy, data);
	return (0);
}
