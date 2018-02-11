/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:47:48 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:13:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		zoom(int keycode, t_wolf *wolf)
{
	if (keycode == 27 && wolf->player->camera < 3)
	{
		wolf->player->direction_x *= 0.99;
		wolf->player->direction_y *= 0.99;
		wolf->player->plane_x *= 1.01;
		wolf->player->plane_y *= 1.01;
		wolf->player->camera *= 1.01;
	}
	else if (keycode == 24 && wolf->player->camera > 1.5)
	{
		wolf->player->direction_x *= 1.01;
		wolf->player->direction_y *= 1.01;
		wolf->player->plane_x *= 0.99;
		wolf->player->plane_y *= 0.99;
		wolf->player->camera *= 0.99;
	}
}

static void		name_map(int keycode, t_wolf *wolf)
{
	size_t	i;

	if (keycode == 18)
		wolf->map->name = "map/map_1";
	else if (keycode == 19)
		wolf->map->name = "map/map_2";
	else if (keycode == 20)
		wolf->map->name = "map/map_3";
	if (keycode == 18 || keycode == 19 || keycode == 20)
	{
		i = 0;
		while (i < wolf->map->height)
		{
			free(wolf->map->array[i]);
			i++;
		}
		free(wolf->map->array);
		open_map(wolf);
		wolf->player->direction_x = -0.5;
		wolf->player->direction_y = 0;
		wolf->player->plane_x = 0;
		wolf->player->plane_y = 0.5;
	}
}

int				key_press(int keycode, t_wolf *wolf)
{
	zoom(keycode, wolf);
	if (keycode == 13)
		wolf->keys->up_down = 1;
	else if (keycode == 1)
		wolf->keys->up_down = -1;
	if (keycode == 14)
		wolf->keys->left_right = 1;
	else if (keycode == 12)
		wolf->keys->left_right = -1;
	if (keycode == 2)
		wolf->keys->rotate = 1;
	else if (keycode == 0)
		wolf->keys->rotate = -1;
	if (keycode == 257)
		wolf->keys->speed = 2;
	return (0);
}

int				key_hook(int keycode, t_wolf *wolf)
{
	if (keycode == 53)
	{
		ft_free(wolf);
		exit(0);
	}
	if (keycode == 50)
	{
		wolf->keys->mode_color++;
		if (wolf->keys->mode_color == 3)
			wolf->keys->mode_color = 0;
	}
	name_map(keycode, wolf);
	if (keycode == 13 || keycode == 1)
		wolf->keys->up_down = 0;
	if (keycode == 14 || keycode == 12)
		wolf->keys->left_right = 0;
	if (keycode == 2 || keycode == 0)
		wolf->keys->rotate = 0;
	if (keycode == 257)
		wolf->keys->speed = 1;
	return (0);
}
