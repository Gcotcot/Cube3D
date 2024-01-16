/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:49:44 by gcot              #+#    #+#             */
/*   Updated: 2023/09/21 15:49:50 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char		*pixel;
	int			i;
	t_imag		*img;

	img = &data->img;
	if ((y >= 0 && x >= 0) && (y < data->height_win && x < data->width_win))
	{
		i = img->bpp - 8;
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

void	background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height_win)
	{
		x = 0;
		while (x < data->width_win)
		{
			if (y >= data->height_win / 2)
				img_pix_put(data, x, y, data->text.floor);
			else
				img_pix_put(data, x, y, data->text.cell);
			x++;
		}
		y++;
	}
}

int	get_tex_color(t_tex tex, int x, int y)
{
	if (x >= 0 && x < tex.width && y >= 0 && y < tex.height)
		return (*(int *)(tex.ptr + (4 * tex.height * y) + (4 * x)));
	return (0x0);
}
