/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:28:00 by rdubois           #+#    #+#             */
/*   Updated: 2023/10/05 16:28:01 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	go_left(t_data *data, double newx, double newy)
{
	double	x;
	double	y;
	double	i;
	double	j;

	x = data->player.pos_x - newx / 8;
	y = data->player.pos_y;
	if (data->map[(int)y][(int)(x)] == '0' \
		|| data->map[(int)y][(int)(x)] == 'O')
		data->player.pos_x -= newx / 10;
	i = data->player.pos_x;
	j = data->player.pos_y - newy / 8;
	if (data->map[(int)(j)][(int)i] == '0' \
		|| data->map[(int)(j)][(int)i] == 'O')
		data->player.pos_y -= newy / 10;
}

void	go_right(t_data *data, double newx, double newy)
{
	double	x;
	double	y;
	double	i;
	double	j;

	x = data->player.pos_x + newx / 8;
	y = data->player.pos_y;
	if (data->map[(int)y][(int)(x)] == '0' \
		|| data->map[(int)y][(int)(x)] == 'O')
		data->player.pos_x += newx / 10;
	i = data->player.pos_x;
	j = data->player.pos_y + newy / 8;
	if (data->map[(int)(j)][(int)i] == '0' \
		|| data->map[(int)(j)][(int)i] == 'O')
		data->player.pos_y += newy / 10;
}

void	go_up(t_data *data, double newx, double newy)
{
	double	x;
	double	y;
	double	i;
	double	j;

	x = data->player.pos_x + newx / 8;
	y = data->player.pos_y;
	if (data->map[(int)y][(int)(x)] == '0' \
		|| data->map[(int)y][(int)(x)] == 'O')
		data->player.pos_x += newx / 10;
	i = data->player.pos_x;
	j = data->player.pos_y - newy / 8;
	if (data->map[(int)(j)][(int)i] == '0' \
		|| data->map[(int)(j)][(int)i] == 'O')
		data->player.pos_y -= newy / 10;
}

void	go_down(t_data *data, double newx, double newy)
{
	double	x;
	double	y;
	double	i;
	double	j;

	x = data->player.pos_x - newx / 8;
	y = data->player.pos_y;
	if (data->map[(int)y][(int)(x)] == '0' \
		|| data->map[(int)y][(int)(x)] == 'O')
		data->player.pos_x -= newx / 10;
	i = data->player.pos_x;
	j = data->player.pos_y + newy / 8;
	if (data->map[(int)(j)][(int)i] == '0' \
		|| data->map[(int)(j)][(int)i] == 'O')
		data->player.pos_y += newy / 10;
}
