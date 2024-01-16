/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:04:02 by gcot              #+#    #+#             */
/*   Updated: 2023/09/22 18:02:29 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	draw_raycaster2(t_data *d, t_draw_ray *r)
{
	if (((double)r->map_y - r->y) >= 0)
		r->map_y--;
	else if (((double)r->map_y - r->y) <= -1)
		r->map_y++;
	if (((double)r->map_x - r->x) >= 0)
		r->map_x--;
	else if (((double)r->map_x - r->x) <= -1)
		r->map_x++;
	if (r->map_y < 0 || r->map_y >= d->height \
		|| r->map_x < 0 || r->map_x >= d->width)
		return (1);
	if (d->map[r->map_y][r->map_x] == '0' || d->map[r->map_y][r->map_x] == 'O')
	{
		if (r->i < d->mini_map.dim * 1.5)
			img_pix_put(d, d->mini_map.dim * 5 + d->mini_map.decal + \
				(r->x - d->player.pos_x) * d->mini_map.dim, d->mini_map.dim * 5 \
				+ d->mini_map.decal + (r->y - d->player.pos_y) * \
				d->mini_map.dim, r->color * 256 * 256 + r->color * 256 + 255);
		r->color += 3;
		if (r->color > 255)
			r->color = 0;
		return (0);
	}
	else
		return (1);
}

void	draw_raycaster(t_data *d, t_draw_ray r)
{
	r.j = d->player.angle - d->player.vision / 2;
	r.nb = 0;
	while (r.j <= d->player.angle + d->player.vision / 2)
	{
		r.map_x = d->player.pos_x;
		r.map_y = d->player.pos_y;
		r.x = d->player.pos_x;
		r.y = d->player.pos_y;
		r.i = 0;
		r.color = d->mini_map.color;
		while (r.i < d->mini_map.dim * 1.5)
		{
			if (draw_raycaster2(d, &r))
				break ;
			r.i++;
			r.y = r.y - (3 / (double)d->mini_map.dim * cos(r.j * (PI / 180)));
			r.x = r.x + (3 / (double)d->mini_map.dim * sin(r.j * (PI / 180)));
		}
		r.j += d->player.vision / (double)d->width_win;
		r.nb++;
	}
}

void	point_carte(t_data *data)
{
	int	x;
	int	y;

	y = data->mini_map.decal + data->mini_map.dim * 4.8;
	while (y <= data->mini_map.decal + data->mini_map.dim * 5.2)
	{
		x = data->mini_map.decal + data->mini_map.dim * 4.8;
		while (x <= data->mini_map.decal + data->mini_map.dim * 5.2)
		{
			img_pix_put(data, x, y, 255 * 256 * 256);
			x++;
		}
		y++;
	}
}

void	mini_map2(t_data *d, t_mini m)
{
	while (++m.j < d->mini_map.dim * 5)
	{
		if ((int)m.x < 0 || (int)m.x >= d->width \
			|| (int)m.y < 0 || (int)m.y >= d->height)
			img_pix_put(d, d->mini_map.dim * 5 + d->mini_map.decal + \
			(m.x - d->player.pos_x) * d->mini_map.dim, d->mini_map.dim \
			* 5 + d->mini_map.decal + (m.y - d->player.pos_y) \
			* d->mini_map.dim, 0);
		else if (d->map[(int)m.y][(int)m.x] == '1')
			img_pix_put(d, d->mini_map.dim * 5 + d->mini_map.decal \
			+ (m.x - d->player.pos_x) * d->mini_map.dim, \
			d->mini_map.dim * 5 + d->mini_map.decal + \
			(m.y - d->player.pos_y) * d->mini_map.dim, 0);
		else if (d->map[(int)m.y][(int)m.x] == 'D')
			img_pix_put(d, d->mini_map.dim * 5 + \
			d->mini_map.decal + (m.x - d->player.pos_x) * \
			d->mini_map.dim, d->mini_map.dim * 5 + d->mini_map.decal + \
			(m.y - d->player.pos_y) * d->mini_map.dim, 6553650);
		else
			img_pix_put(d, d->mini_map.dim * 5 + d->mini_map.decal \
			+ (m.x - d->player.pos_x) * d->mini_map.dim, d->mini_map.dim \
			* 5 + d->mini_map.decal + (m.y - d->player.pos_y) * \
			d->mini_map.dim, 255 * 256 * 256 + 255 * 256 + 255);
		m.x = m.x + (1 / (double)d->mini_map.dim * sin(m.angle * (PI / 180)));
	}
}

void	mini_map(t_data *data)
{
	trueraycaster(data);
	data->mini.angle = 0;
	while (data->mini.angle < 360)
	{
		data->mini.y = data->player.pos_y;
		data->mini.i = 0;
		while (data->mini.i < data->mini_map.dim * 5)
		{
			data->mini.x = data->player.pos_x;
			data->mini.j = -1;
			mini_map2(data, data->mini);
			data->mini.y = data->mini.y - (1 / (double)data->mini_map.dim \
				* cos(data->mini.angle * (PI / 180)));
			data->mini.i++;
		}
		data->mini.angle += 5;
	}
	point_carte(data);
	draw_raycaster(data, data->draw_ray);
}
