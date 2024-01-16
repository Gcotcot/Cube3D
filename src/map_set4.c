/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:09:08 by gcot              #+#    #+#             */
/*   Updated: 2023/10/05 15:09:10 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	verif_line2(t_data *data, char *line, int i)
{
	if (!ft_strchrstr(line, "SO"))
	{
		if (data->text.wall_s)
			return (ft_error("double textures"));
		data->text.wall_s = ft_copy_b_to_z(line, i);
	}
	else if (!ft_strchrstr(line, "WE"))
	{
		if (data->text.wall_w)
			return (ft_error("double textures"));
		data->text.wall_w = ft_copy_b_to_z(line, i);
	}
	else if (!ft_strchrstr(line, "EA"))
	{
		if (data->text.wall_e)
			return (ft_error("double textures"));
		data->text.wall_e = ft_copy_b_to_z(line, i);
	}
	else
		return (2);
	return (0);
}

int	verif_line(t_data *data, char *line)
{
	int	i;

	if (!ft_strchr(line, 'C') || !ft_strchr(line, 'F'))
		return (ft_set_floor_cell(data, line));
	else
	{
		i = 0;
		while (line[i] && line[i] != '.')
			i++;
		if (!ft_strchrstr(line, "NO"))
		{
			if (data->text.wall_n)
				return (ft_error("double textures"));
			data->text.wall_n = ft_copy_b_to_z(line, i);
		}
		else
			return (verif_line2(data, line, i));
	}
	return (0);
}
