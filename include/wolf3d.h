/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 19:56:08 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:48:11 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/src/get_next_line.h"
# include "../libft/src/libft.h"
# include "../minilibX/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>
# define W 800
# define H 400
# define K_T 5

typedef struct	s_rgb
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}				t_rgb;

typedef union	u_color
{
	int			value;
	t_rgb		rgb;
}				t_color;

typedef struct	s_texture
{
	int			pixel_size;
	void		*img_ptr;
	char		*ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_texture;

typedef	struct	s_rays
{
	float		position_x;
	float		position_y;
	int			map_x;
	int			map_y;
	float		camera_x;
	float		direction_x;
	float		direction_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		perp_wall_dist;
	int			hit;
	int			side;
	int			step_x;
	int			step_y;
	float		side_x;
	float		side_y;
	int			line_height;
}				t_rays;

typedef struct	s_keys
{
	int			up_down;
	int			left_right;
	int			rotate;
	int			speed;
	int			mode_color;
}				t_keys;

typedef struct	s_player
{
	float		position_x;
	float		position_y;
	float		direction_x;
	float		direction_y;
	float		plane_x;
	float		plane_y;
	float		camera;
	float		speed_move;
	float		speed_rotate;
}				t_player;

typedef struct	s_map
{
	char		*name;
	size_t		width;
	size_t		height;
	int			**array;
	int			status;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			fps;
}				t_mlx;

typedef struct	s_wolf
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	t_keys		*keys;
	t_rays		*rays;
	t_texture	texture[K_T];
}				t_wolf;

t_wolf			*init_wolf(void);
t_rays			*init_rays(t_wolf *wolf);
void			open_map(t_wolf *wolf);
void			error(int status, t_wolf *wolf);
void			ft_free(t_wolf *wolf);
void			init_texture(t_wolf *wolf);
int				expose_hook(t_wolf *wolf);
void			ray_casting(t_wolf *wolf);
void			draw_line(t_wolf *wolf, int x, int draw_start, int draw_end);
int				get_color(t_wolf *wolf);
void			set_texture(int x, int i, t_wolf *wolf);
int				key_hook(int keycode, t_wolf *wolf);
int				key_press(int keycode, t_wolf *wolf);
int				esc(t_wolf *wolf);
void			move_up_down(t_wolf *wolf);
void			move_left_right(t_wolf *wolf);
void			move_rotate_left(t_wolf *wolf);
void			move_rotate_right(t_wolf *wolf);
void			fps(t_wolf *wolf);
void			tutorial(void);
#endif
