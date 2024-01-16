/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:54 by gcot              #+#    #+#             */
/*   Updated: 2023/09/19 15:40:42 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	set_info2(t_data *data, int fd, int count, char *line)
{
	if (count != 6)
	{
		free(line);
		line = get_next_line(-100);
		return (ft_error("number infos map"));
	}
	return (ft_dimension(data, line, fd));
}

int	set_info(t_data *data, int fd, int i)
{
	char	*line;
	int		count;
	int		t;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->line = ++i;
		t = verif_line(data, line);
		if (t == 0)
			count++;
		else if (t == 1)
		{
			free(line);
			line = get_next_line(-100);
			return (1);
		}
		else if (!ft_strchr(line, '1') || !ft_strchr(line, '0'))
			return (set_info2(data, fd, count, line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_error("file infos map"));
}

int	load_tex2(t_data *data)
{
	data->tex_e.tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->text.wall_e, &data->tex_e.width, &data->tex_e.height);
	if (!data->tex_e.tex)
		return (ft_error("invalid texture path east"));
	data->tex_e.ptr = mlx_get_data_addr(data->tex_e.tex, \
		&data->tex_e.bpp, &data->tex_e.size_line, &data->tex_e.endian);
	data->tex_d.tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./images/door.xpm", &data->tex_d.width, &data->tex_d.height);
	if (!data->tex_d.tex)
		return (ft_error("invalid texture path door"));
	data->tex_d.ptr = mlx_get_data_addr(data->tex_d.tex, \
		&data->tex_d.bpp, &data->tex_d.size_line, &data->tex_d.endian);
	return (0);
}

int	load_tex(t_data *data)
{
	data->tex_n.tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->text.wall_n, &data->tex_n.width, &data->tex_n.height);
	if (!data->tex_n.tex)
		return (ft_error("invalid texture path north"));
	data->tex_n.ptr = mlx_get_data_addr(data->tex_n.tex, \
		&data->tex_n.bpp, &data->tex_n.size_line, &data->tex_n.endian);
	data->tex_s.tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->text.wall_s, &data->tex_s.width, &data->tex_s.height);
	if (!data->tex_s.tex)
		return (ft_error("invalid texture path south"));
	data->tex_s.ptr = mlx_get_data_addr(data->tex_s.tex, \
		&data->tex_s.bpp, &data->tex_s.size_line, &data->tex_s.endian);
	data->tex_w.tex = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->text.wall_w, &data->tex_w.width, &data->tex_w.height);
	if (!data->tex_w.tex)
		return (ft_error("invalid texture path west"));
	data->tex_w.ptr = mlx_get_data_addr(data->tex_w.tex, \
		&data->tex_w.bpp, &data->tex_w.size_line, &data->tex_w.endian);
	return (load_tex2(data));
}

int	get_map(t_data *data, char *file)
{
	int	fd;

	if (verif_cub(file))
		return (1);
	fd = open(file, O_RDONLY);
	if (set_info(data, fd, 0))
	{
		close(fd);
		return (1);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (set_map(data, fd))
		return (1);
	close(fd);
	if (verif_map(data))
		return (1);
	if (get_player(data))
		return (1);
	if (modif_map(data, data->map))
		return (1);
	if (load_tex(data))
		return (1);
	return (0);
}
