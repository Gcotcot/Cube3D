/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:14:39 by rdubois           #+#    #+#             */
/*   Updated: 2023/10/05 16:14:40 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 'a')
		data->key.left = false;
	else if (keysym == 'd')
		data->key.right = false;
	else if (keysym == 'w')
		data->key.up = false;
	else if (keysym == 's')
		data->key.down = false;
	else if (keysym == 65363)
		data->key.right_arrow = false;
	else if (keysym == 65361)
		data->key.left_arrow = false;
	return (0);
}

void	keypress2(int keysym, t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos_x + data->player.delta_x;
	y = data->player.pos_y - data->player.delta_y;
	if (keysym == 'e')
	{
		if (data->map[(int)(y)][(int)(x)] == 'D')
			data->map[(int)(y)][(int)(x)] = 'O';
		else if (data->map[(int)(y)][(int)(x)] == 'O')
			data->map[(int)(y)][(int)(x)] = 'D';
	}
	else if (keysym == 65363)
		data->key.right_arrow = true;
	else if (keysym == 65361)
		data->key.left_arrow = true;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		return (close_win(data));
	else if (keysym == 'a')
		data->key.left = true;
	else if (keysym == 'd')
		data->key.right = true;
	else if (keysym == 'w')
		data->key.up = true;
	else if (keysym == 's')
		data->key.down = true;
	else if (keysym == 'q')
	{
		if (data->key.unlock)
			data->key.unlock = false;
		else
			data->key.unlock = true;
	}
	else
		keypress2(keysym, data);
	return (0);
}
