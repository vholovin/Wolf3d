/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:25:36 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:09:21 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		set_wall(int x, int i, int tex_x, t_wolf *wolf)
{
	int		d;
	int		num;
	int		tex_y;

	num = wolf->map->array[wolf->rays->map_y][wolf->rays->map_x] - 1;
	if (num > 4)
		num = 4;
	d = i * 256 - H * 128 + wolf->rays->line_height * 128;
	tex_y = abs((d * wolf->texture->pixel_size) /
			wolf->rays->line_height) / 256;
	ft_memcpy(&wolf->mlx->ptr[(int)(x * 4 + i * H * 8)],
		&wolf->texture[num].ptr[tex_y * wolf->texture[num].pixel_size * 4
		+ tex_x % wolf->texture[num].pixel_size * 4],
		ft_strlen(wolf->texture[num].ptr));
}

void			set_texture(int x, int i, t_wolf *wolf)
{
	float	wall;
	int		tex_x;

	tex_x = 0;
	if (wolf->rays->side == 0)
		wall = wolf->rays->position_y + wolf->rays->perp_wall_dist *
			wolf->rays->direction_y;
	else
		wall = wolf->rays->position_x + wolf->rays->perp_wall_dist *
			wolf->rays->direction_x;
	tex_x = (int)(wall * (double)(wolf->texture->pixel_size));
	if (wolf->rays->side == 0 && wolf->rays->direction_x > 0)
		tex_x = wolf->texture->pixel_size - tex_x - 1;
	if (wolf->rays->side == 1 && wolf->rays->direction_y < 0)
		tex_x = wolf->texture->pixel_size - tex_x - 1;
	tex_x = abs(tex_x);
	set_wall(x, i, tex_x, wolf);
}
