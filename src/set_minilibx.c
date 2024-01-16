/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:57:48 by rdubois           #+#    #+#             */
/*   Updated: 2023/09/19 14:59:13 by rdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_data2(t_data *data)
{
	if (data->text.wall_n)
		free(data->text.wall_n);
	if (data->text.wall_s)
		free(data->text.wall_s);
	if (data->text.wall_w)
		free(data->text.wall_w);
	if (data->text.wall_e)
		free(data->text.wall_e);
	if (data->tex_n.tex)
		mlx_destroy_image(data->mlx_ptr, data->tex_n.tex);
	if (data->tex_s.tex)
		mlx_destroy_image(data->mlx_ptr, data->tex_s.tex);
	if (data->tex_w.tex)
		mlx_destroy_image(data->mlx_ptr, data->tex_w.tex);
	if (data->tex_e.tex)
		mlx_destroy_image(data->mlx_ptr, data->tex_e.tex);
	if (data->tex_d.tex)
		mlx_destroy_image(data->mlx_ptr, data->tex_d.tex);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->height)
			free(data->map[i++]);
		free(data->map);
	}
	i = 0;
	while (i < 6)
	{
		if (data->tex_t[i].tex)
			mlx_destroy_image(data->mlx_ptr, data->tex_t[i].tex);
		i++;
	}
	free_data2(data);
}

void	init_torche(t_data *data)
{
	data->tex_t[0].tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./images/frame-1.xpm", &data->tex_t[0].width, &data->tex_t[0].height);
	data->tex_t[0].ptr = mlx_get_data_addr(data->tex_t[0].tex, \
		&data->tex_t[0].bpp, &data->tex_t[0].size_line, &data->tex_t[0].endian);
	data->tex_t[1].tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./images/frame-2.xpm", &data->tex_t[1].width, &data->tex_t[1].height);
	data->tex_t[1].ptr = mlx_get_data_addr(data->tex_t[1].tex, \
		&data->tex_t[1].bpp, &data->tex_t[1].size_line, &data->tex_t[1].endian);
	data->tex_t[2].tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./images/frame-3.xpm", &data->tex_t[2].width, &data->tex_t[2].height);
	data->tex_t[2].ptr = mlx_get_data_addr(data->tex_t[2].tex, \
		&data->tex_t[2].bpp, &data->tex_t[2].size_line, &data->tex_t[2].endian);
	data->tex_t[3].tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./images/frame-4.xpm", &data->tex_t[3].width, &data->tex_t[3].height);
	data->tex_t[3].ptr = mlx_get_data_addr(data->tex_t[3].tex, \
		&data->tex_t[3].bpp, &data->tex_t[3].size_line, &data->tex_t[3].endian);
	data->tex_t[4].tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./images/frame-5.xpm", &data->tex_t[4].width, &data->tex_t[4].height);
	data->tex_t[4].ptr = mlx_get_data_addr(data->tex_t[4].tex, \
		&data->tex_t[4].bpp, &data->tex_t[4].size_line, &data->tex_t[4].endian);
	data->tex_t[5].tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./images/frame-6.xpm", &data->tex_t[5].width, &data->tex_t[5].height);
	data->tex_t[5].ptr = mlx_get_data_addr(data->tex_t[5].tex, \
		&data->tex_t[5].bpp, &data->tex_t[5].size_line, &data->tex_t[5].endian);
}

int	stop(t_data *data)
{
	free_data(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
