/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:49:32 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:08:11 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		calculate_distance(t_wolf *wolf)
{
	if (wolf->rays->side == 0)
		wolf->rays->perp_wall_dist = (wolf->rays->map_x -
			wolf->rays->position_x + (1 - wolf->rays->step_x) / 2) /
			wolf->rays->direction_x;
	else
		wolf->rays->perp_wall_dist = (wolf->rays->map_y -
			wolf->rays->position_y + (1 - wolf->rays->step_y) / 2) /
			wolf->rays->direction_y;
}

static void		calculate_dda(t_wolf *wolf)
{
	while (wolf->rays->hit == 0)
	{
		if (wolf->rays->side_x < wolf->rays->side_y)
		{
			wolf->rays->side_x += wolf->rays->delta_dist_x;
			wolf->rays->map_x += wolf->rays->step_x;
			wolf->rays->side = 0;
		}
		else
		{
			wolf->rays->side_y += wolf->rays->delta_dist_y;
			wolf->rays->map_y += wolf->rays->step_y;
			wolf->rays->side = 1;
		}
		if (wolf->map->array[wolf->rays->map_y][wolf->rays->map_x] > 0)
			wolf->rays->hit = 1;
	}
}

static void		calculate_step_side(t_wolf *wolf)
{
	if (wolf->rays->direction_x < 0)
	{
		wolf->rays->step_x = -1;
		wolf->rays->side_x = (wolf->rays->position_x -
			(int)wolf->rays->position_x) * wolf->rays->delta_dist_x;
	}
	else
	{
		wolf->rays->step_x = 1;
		wolf->rays->side_x = ((int)wolf->rays->position_x + 1 -
			wolf->rays->position_x) * wolf->rays->delta_dist_x;
	}
	if (wolf->rays->direction_y < 0)
	{
		wolf->rays->step_y = -1;
		wolf->rays->side_y = (wolf->rays->position_y -
			(int)wolf->rays->position_y) * wolf->rays->delta_dist_y;
	}
	else
	{
		wolf->rays->step_y = 1;
		wolf->rays->side_y = ((int)wolf->rays->position_y + 1 -
			wolf->rays->position_y) * wolf->rays->delta_dist_y;
	}
}

static void		calculate_position_direction(t_wolf *wolf)
{
	wolf->rays->position_x = wolf->player->position_x;
	wolf->rays->position_y = wolf->player->position_y;
	wolf->rays->direction_x = wolf->player->direction_x + wolf->player->plane_x
		* wolf->rays->camera_x;
	wolf->rays->direction_y = wolf->player->direction_y + wolf->player->plane_y
		* wolf->rays->camera_x;
	wolf->rays->map_x = (int)wolf->rays->position_x;
	wolf->rays->map_y = (int)wolf->rays->position_y;
	wolf->rays->delta_dist_x = sqrt(1 + (wolf->rays->direction_y *
		wolf->rays->direction_y) / (wolf->rays->direction_x *
		wolf->rays->direction_x));
	wolf->rays->delta_dist_y = sqrt(1 + (wolf->rays->direction_x *
		wolf->rays->direction_x) / (wolf->rays->direction_y *
		wolf->rays->direction_y));
	wolf->rays->hit = 0;
}

void			ray_casting(t_wolf *wolf)
{
	int		x;
	int		draw_start;
	int		draw_end;

	x = 0;
	while (x < W)
	{
		wolf->rays->camera_x = wolf->player->camera * x / (double)W
			- wolf->player->camera / 2;
		calculate_position_direction(wolf);
		calculate_step_side(wolf);
		calculate_dda(wolf);
		calculate_distance(wolf);
		wolf->rays->line_height = (int)(H / wolf->rays->perp_wall_dist);
		draw_start = -wolf->rays->line_height / 2 + H / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = wolf->rays->line_height / 2 + H / 2;
		if (draw_end >= H)
			draw_end = H - 1;
		draw_line(wolf, x, draw_start, draw_end);
		++x;
	}
}
