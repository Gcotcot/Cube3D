/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:39:06 by rdubois           #+#    #+#             */
/*   Updated: 2023/09/22 14:21:44 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	background(data);
	data->mini_map.color -= 2;
	if (data->mini_map.color < 150)
		data->mini_map.color -= 2;
	else
		data->mini_map.color -= 10;
	if (data->mini_map.color < 0)
		data->mini_map.color = 255;
	mini_map(data);
	moving(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.mlx_img, 0, 0);
	data->anim++;
	if (data->anim > 5)
		data->anim = 0;
	return (0);
}

void	datainit2(t_data *data)
{
	data->text.wall_n = NULL;
	data->text.wall_s = NULL;
	data->text.wall_w = NULL;
	data->text.wall_e = NULL;
	data->tex_n.tex = NULL;
	data->tex_s.tex = NULL;
	data->tex_w.tex = NULL;
	data->tex_e.tex = NULL;
	data->tex_d.tex = NULL;
	data->text.wall_n = NULL;
	data->text.wall_s = NULL;
	data->text.wall_w = NULL;
	data->text.wall_e = NULL;
}

void	datainit(t_data *data)
{
	data->width_win = 1920;
	data->height_win = 1080;
	data->key.up = false;
	data->key.down = false;
	data->key.left = false;
	data->key.right = false;
	data->key.left_arrow = false;
	data->key.right_arrow = false;
	data->key.unlock = false;
	data->mini_map.dim = 15;
	data->mini_map.decal = 5;
	data->mini_map.color = 255;
	data->anim = 0;
	data->map = NULL;
	datainit2(data);
}

void	main2(t_data *data)
{
	data->anim = 0;
	mlx_loop_hook(data->mlx_ptr, &render, data);
	if (HD == 1)
		mlx_mouse_hide(data->mlx_ptr, data->win_ptr);
	mlx_mouse_move(data->mlx_ptr, data->win_ptr, \
		data->width_win / 2, data->height_win / 2);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, \
		&handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, \
		&handle_keyrelease, data);
	mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, \
		&mouse_event, data);
	mlx_hook(data->win_ptr, 17, 1, &close_win, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data		data;

	(void)argv;
	if (argc != 2)
	{
		printf("Error !\nThe number of arguements are incorrect\n");
		return (0);
	}
	datainit(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.width_win, \
		data.height_win, "The boite 3D");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, \
		data.width_win, data.height_win);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, \
		&data.img.bpp, &data.img.line_len, &data.img.endian);
	init_torche(&data);
	if (get_map(&data, argv[1]))
		stop(&data);
	data.mini_map.dim = 15;
	data.mini_map.decal = 5;
	data.mini_map.color = 255;
	main2(&data);
	stop(&data);
	return (0);
}
