/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:18:43 by gcot              #+#    #+#             */
/*   Updated: 2023/10/05 16:18:46 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	draw_torch2(t_data *d, int i, t_line l)
{
	if ((d->ray.side == 0 && d->ray.raydirx > 0) \
		|| (d->ray.side == 1 && d->ray.raydiry < 0))
		l.tex_x = l.tex.width - l.tex_x - 1;
	l.step = (double)l.tex.height / (double)d->ray.lineheight;
	l.tex_pos = (d->ray.drawstart - d->height_win \
		/ 2 + d->ray.lineheight / 2) * l.step;
	while (d->ray.drawstart++ <= d->ray.drawend)
	{
		l.tex_y = (int)l.tex_pos;
		l.tex_pos += l.step;
		d->ray.color = get_tex_color(l.tex, l.tex_x, l.tex_y);
		if (d->ray.color > 10)
			img_pix_put(d, i, d->ray.drawstart, d->ray.color);
	}
}

void	draw_torch(t_data *d, int i, t_line l)
{
	d->ray.drawstart = -d->ray.lineheight / 2 + d->height_win / 2;
	if (d->ray.drawstart < 0)
		d->ray.drawstart = 0;
	d->ray.drawend = d->ray.lineheight / 2 + d->height_win / 2;
	if (d->ray.drawend >= d->height_win)
		d->ray.drawend = d->height_win - 1;
	if (d->ray.side == 0)
		l.wall_x = -d->player.pos_y + d->ray.perpwalldist * d->ray.raydiry;
	else
		l.wall_x = d->player.pos_x + d->ray.perpwalldist * d->ray.raydirx;
	l.wall_x -= floor((l.wall_x));
	l.tex = d->tex_t[d->anim];
	l.tex_x = (int)(l.wall_x * l.tex.width);
	draw_torch2(d, i, l);
}

void	draw_wall2(t_data *d, int i, t_line l)
{
	if (d->map[d->ray.mapy][d->ray.mapx] == 'D')
		l.tex = d->tex_d;
	l.tex_x = (int)(l.wall_x * l.tex.width);
	if ((d->ray.side == 0 && d->ray.raydirx > 0) \
		|| (d->ray.side == 1 && d->ray.raydiry < 0))
		l.tex_x = l.tex.width - l.tex_x - 1;
	l.step = (double)l.tex.height / (double)d->ray.lineheight;
	l.tex_pos = (d->ray.drawstart - d->height_win \
		/ 2 + d->ray.lineheight / 2) * l.step;
	while (d->ray.drawstart++ <= d->ray.drawend)
	{
		l.tex_y = (int)l.tex_pos;
		l.tex_pos += l.step;
		d->ray.color = get_tex_color(l.tex, l.tex_x, l.tex_y);
		img_pix_put(d, i, d->ray.drawstart, d->ray.color);
	}
	if (d->map[d->ray.mapy][d->ray.mapx] == '1' && \
		(d->ray.mapy % 3 == 0 && d->ray.mapx % 3 == 0))
		draw_torch(d, i, l);
}

void	draw_wall(t_data *d, int i, t_line l)
{
	if (d->ray.side == 0)
		l.wall_x = -d->player.pos_y + d->ray.perpwalldist * d->ray.raydiry;
	else
		l.wall_x = d->player.pos_x + d->ray.perpwalldist * d->ray.raydirx;
	l.wall_x -= floor((l.wall_x));
	if (d->ray.side == 1)
	{
		if (d->ray.stepy == -1)
			l.tex = d->tex_n;
		else
			l.tex = d->tex_s;
	}
	else
	{
		if (d->ray.stepx == -1)
			l.tex = d->tex_w;
		else
			l.tex = d->tex_e;
	}
	draw_wall2(d, i, l);
}
