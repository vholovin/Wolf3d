/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:01:30 by vholovin          #+#    #+#             */
/*   Updated: 2017/07/20 18:20:00 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int		rgb_set(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1.value);
	c.rgb.r = (char)ft_lerpi((int)c1.rgb.r, (int)c2.rgb.r, p);
	c.rgb.g = (char)ft_lerpi((int)c1.rgb.g, (int)c2.rgb.g, p);
	c.rgb.b = (char)ft_lerpi((int)c1.rgb.b, (int)c2.rgb.b, p);
	return (c.value);
}

static t_color	type_0(t_wolf *wolf)
{
	t_color color;

	color.value = 0xFF0000;
	if (wolf->rays->side == 1)
	{
		if ((wolf->rays->step_x == -1 && wolf->rays->step_y == -1) ||
			(wolf->rays->step_x == 1 && wolf->rays->step_y == -1))
			color.value = 0xFF00FF;
		if ((wolf->rays->step_x == -1 && wolf->rays->step_y == 1) ||
			(wolf->rays->step_x == 1 && wolf->rays->step_y == 1))
			color.value = 0x00FF00;
		return (color);
	}
	if ((wolf->rays->step_x == -1 && wolf->rays->step_y == -1) ||
			(wolf->rays->step_x == -1 && wolf->rays->step_y == 1))
		color.value = 0x0000FF;
	return (color);
}

static t_color	type_1(t_wolf *wolf)
{
	t_color color;
	t_color	black;

	black.value = 0x000000;
	color.value = 0xFFFF00;
	if (wolf->map->array[wolf->rays->map_y][wolf->rays->map_x] == 1)
		color.value = 0xFFFFFF;
	if (wolf->map->array[wolf->rays->map_y][wolf->rays->map_x] == 2)
		color.value = 0xFF0000;
	else if (wolf->map->array[wolf->rays->map_y][wolf->rays->map_x] == 3)
		color.value = 0x00FF00;
	else if (wolf->map->array[wolf->rays->map_y][wolf->rays->map_x] == 4)
		color.value = 0x0000FF;
	if (wolf->rays->side == 1)
		color.value = rgb_set(color, black, 0.5);
	return (color);
}

int				get_color(t_wolf *wolf)
{
	t_color	color;
	t_color black;
	double	d;

	black.value = 0x000000;
	if (wolf->keys->mode_color == 0)
		color = type_0(wolf);
	else
		color = type_1(wolf);
	d = 5 / (100 / wolf->rays->perp_wall_dist);
	if (d > 0.9)
		d = 0.9;
	color.value = rgb_set(color, black, d);
	return (color.value);
}
