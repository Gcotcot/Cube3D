/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:39:52 by rdubois           #+#    #+#             */
/*   Updated: 2023/09/22 17:04:29 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <X11/X.h>
# include <stdbool.h>

# define PI 3.1415926535
# define HD 0

typedef struct s_ray
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	olddirx;
	double	oldplanex;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
}	t_ray;

typedef struct s_text
{
	char	*wall_n;
	char	*wall_s;
	char	*wall_e;
	char	*wall_w;
	int		cell;
	int		floor;
}	t_text;

typedef struct s_tex
{
	char	*path;
	void	*ptr;
	void	*tex;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_tex;

typedef struct s_imag
{
	void	*mlx_img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imag;

typedef struct s_mini
{
	double	y;
	double	x;
	double	i;
	double	j;
	double	angle;
}	t_mini;

typedef struct s_draw_ray
{
	double	x;
	double	y;
	double	i;
	double	j;
	int		map_x;
	int		map_y;
	int		nb;
	int		color;
}	t_draw_ray;

typedef struct s_line
{
	int		tex_y;
	int		tex_x;
	double	step;
	double	tex_pos;
	double	wall_x;
	t_tex	tex;
}	t_line;

typedef struct s_mini_map
{
	int	decal;
	int	dim;
	int	color;
}	t_mini_map;

typedef struct s_player
{
	int		opos_x;
	int		opos_y;
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	angle;
	double	vision;
}	t_player;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	i;
}	t_color;

typedef struct s_key
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	left_arrow;
	bool	right_arrow;
	bool	unlock;
}	t_key;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			width_win;
	int			height_win;
	int			line;
	int			anim;
	char		**map;
	t_mini_map	mini_map;
	t_player	player;
	t_text		text;
	t_imag		img;
	t_key		key;
	t_ray		ray;
	t_tex		tex_n;
	t_tex		tex_s;
	t_tex		tex_w;
	t_tex		tex_e;
	t_tex		tex_d;
	t_tex		tex_t[6];
	t_mini		mini;
	t_draw_ray	draw_ray;
	t_line		line_wall;
	t_color		color;
}	t_data;

int		stop(t_data *data);
int		get_map(t_data *data, char *file);
int		ft_dimension(t_data *data, char *line, int fd);
int		set_map(t_data *data, int fd);
int		ft_strchrstr(char *s1, char *s2);
int		get_player(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		close_win(t_data *data);
int		verif_map(t_data *data);
int		mouse_event(int x, int y, t_data *data);
int		moving(t_data *data);
int		get_tex_color(t_tex tex, int x, int y);
int		ft_error(char *str);
int		verif_line(t_data *data, char *line);
int		verif_cub(char *file);
int		modif_map(t_data *data, char **map);
int		ft_set_floor_cell(t_data *data, char *line);
char	*ft_copy_b_to_z(char *line, int i);
void	background(t_data *data);
void	img_pix_put(t_data *data, int x, int y, int color);
void	mini_map(t_data *data);
void	raycaster(t_data *d);
void	trueraycaster(t_data *data);
void	draw_wall(t_data *data, int i, t_line l);
void	init_torche(t_data *data);
void	free_map(t_data *data);
void	go_up(t_data *data, double newx, double newy);
void	go_down(t_data *data, double newx, double newy);
void	go_right(t_data *data, double newx, double newy);
void	go_left(t_data *data, double newx, double newy);
void	set_cam(t_data *data);
void	mouse_right(t_data *data);
void	mouse_left(t_data *data);

#endif
