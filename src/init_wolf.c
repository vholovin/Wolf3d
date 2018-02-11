/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:20:38 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/08 18:40:48 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static t_map	*init_map(t_wolf *wolf)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		error(0, wolf);
	map->name = "map/map_1";
	return (map);
}

static t_keys	*init_keys(t_wolf *wolf)
{
	t_keys *keys;

	if (!(keys = (t_keys*)malloc(sizeof(t_keys))))
		error(0, wolf);
	keys->up_down = 0;
	keys->left_right = 0;
	keys->rotate = 0;
	keys->speed = 1;
	keys->mode_color = 0;
	return (keys);
}

static t_player	*init_player(t_wolf *wolf)
{
	t_player *player;

	if (!(player = (t_player*)malloc(sizeof(t_player))))
		error(0, wolf);
	player->position_x = 0;
	player->position_y = 0;
	player->direction_x = -0.5;
	player->direction_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.5;
	player->camera = 2;
	player->speed_move = 0.2;
	player->speed_rotate = 0.1;
	return (player);
}

static t_mlx	*init_mlx(t_wolf *wolf)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		error(0, wolf);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W, H, "Wolf3D_42");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W, H);
	mlx->ptr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	mlx->fps = 25;
	return (mlx);
}

t_wolf			*init_wolf(void)
{
	t_wolf	*wolf;

	if (!(wolf = (t_wolf*)malloc(sizeof(t_wolf))))
		error(0, wolf);
	wolf->mlx = init_mlx(wolf);
	wolf->player = init_player(wolf);
	wolf->rays = init_rays(wolf);
	wolf->keys = init_keys(wolf);
	wolf->map = init_map(wolf);
	open_map(wolf);
	init_texture(wolf);
	return (wolf);
}
