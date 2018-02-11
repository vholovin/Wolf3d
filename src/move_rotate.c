/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:25:19 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:07:52 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int	cross_wall(float d_x, float d_y, t_wolf *wolf)
{
	if (wolf->map->array[(int)(wolf->player->position_y + 0.025 + d_y)]
			[(int)(wolf->player->position_x + 0.025 + d_x)] == 0 &&
		wolf->map->array[(int)(wolf->player->position_y - 0.025 + d_y)]
			[(int)(wolf->player->position_x - 0.025 + d_x)] == 0 &&
		wolf->map->array[(int)(wolf->player->position_y + 0.025 + d_y)]
			[(int)(wolf->player->position_x - 0.025 + d_x)] == 0 &&
		wolf->map->array[(int)(wolf->player->position_y - 0.025 + d_y)]
			[(int)(wolf->player->position_x + 0.025 + d_x)] == 0)
		return (0);
	else
		return (1);
}

void		move_rotate_left(t_wolf *wolf)
{
	float x;
	float y;

	if (wolf->keys->rotate == 1)
	{
		x = wolf->player->direction_x;
		y = wolf->player->direction_y;
		wolf->player->direction_x = x * cos(-wolf->player->speed_rotate) -
			y * sin(-wolf->player->speed_rotate);
		wolf->player->direction_y = x * sin(-wolf->player->speed_rotate) +
			y * cos(-wolf->player->speed_rotate);
		x = wolf->player->plane_x;
		y = wolf->player->plane_y;
		wolf->player->plane_x = x * cos(-wolf->player->speed_rotate) -
			y * sin(-wolf->player->speed_rotate);
		wolf->player->plane_y = x * sin(-wolf->player->speed_rotate) +
			y * cos(-wolf->player->speed_rotate);
	}
}

void		move_rotate_right(t_wolf *wolf)
{
	float x;
	float y;

	if (wolf->keys->rotate == -1)
	{
		x = wolf->player->direction_x;
		y = wolf->player->direction_y;
		wolf->player->direction_x = x * cos(wolf->player->speed_rotate) -
			y * sin(wolf->player->speed_rotate);
		wolf->player->direction_y = x * sin(wolf->player->speed_rotate) +
			y * cos(wolf->player->speed_rotate);
		x = wolf->player->plane_x;
		y = wolf->player->plane_y;
		wolf->player->plane_x = x * cos(wolf->player->speed_rotate) -
			y * sin(wolf->player->speed_rotate);
		wolf->player->plane_y = x * sin(wolf->player->speed_rotate) +
			y * cos(wolf->player->speed_rotate);
	}
}

void		move_up_down(t_wolf *wolf)
{
	if (wolf->keys->up_down == 1)
	{
		if (!cross_wall(wolf->player->direction_x * wolf->player->speed_move,
				0, wolf))
			wolf->player->position_x += wolf->player->direction_x *
				wolf->player->speed_move;
		if (!cross_wall(0, wolf->player->direction_y * wolf->player->speed_move,
				wolf))
			wolf->player->position_y += wolf->player->direction_y *
				wolf->player->speed_move;
	}
	else if (wolf->keys->up_down == -1)
	{
		if (!cross_wall(-wolf->player->direction_x * wolf->player->speed_move,
				0, wolf))
			wolf->player->position_x -= wolf->player->direction_x *
				wolf->player->speed_move;
		if (!cross_wall(0, -wolf->player->direction_y *
				wolf->player->speed_move, wolf))
			wolf->player->position_y -= wolf->player->direction_y *
				wolf->player->speed_move;
	}
}

void		move_left_right(t_wolf *wolf)
{
	if (wolf->keys->left_right == 1)
	{
		if (!cross_wall(wolf->player->direction_y * wolf->player->speed_move,
				0, wolf))
			wolf->player->position_x += wolf->player->direction_y *
				wolf->player->speed_move;
		if (!cross_wall(0, wolf->player->direction_x *
				-wolf->player->speed_move, wolf))
			wolf->player->position_y -= wolf->player->direction_x *
				wolf->player->speed_move;
	}
	else if (wolf->keys->left_right == -1)
	{
		if (!cross_wall(wolf->player->direction_y * -wolf->player->speed_move,
				0, wolf))
			wolf->player->position_x -= wolf->player->direction_y *
				wolf->player->speed_move;
		if (!cross_wall(0, wolf->player->direction_x * wolf->player->speed_move,
				wolf))
			wolf->player->position_y += wolf->player->direction_x *
				wolf->player->speed_move;
	}
}
