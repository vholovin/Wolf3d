/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:19:10 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:09:36 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		info(t_wolf *wolf)
{
	char *fps;

	fps = ft_itoa(wolf->mlx->fps);
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr,
		5, 5, 0xFFFFFF, "fps:");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr,
		45, 5, 0xFFFFFF, fps);
	free(fps);
}

static void		mlx_put_pixel_to_image(int y, int x, int color, t_mlx *mlx)
{
	unsigned int	new_color;
	int				i;

	new_color = mlx_get_color_value(mlx->mlx_ptr, color);
	i = x * 4 + y * mlx->size_line;
	mlx->ptr[i] = (new_color & 0xFF);
	mlx->ptr[i + 1] = (new_color & 0xFF00) >> 8;
	mlx->ptr[i + 2] = (new_color & 0xFF0000) >> 16;
}

void			draw_line(t_wolf *wolf, int x, int draw_start, int draw_end)
{
	int	i;

	i = 0;
	while (i < draw_start)
	{
		mlx_put_pixel_to_image(i, x, 0x67C8FF, wolf->mlx);
		++i;
	}
	if (i > 0)
		--i;
	while (i <= draw_end && i < H)
	{
		if (wolf->keys->mode_color == 2)
			set_texture(x, i, wolf);
		else
			mlx_put_pixel_to_image(i, x, get_color(wolf), wolf->mlx);
		++i;
	}
	--i;
	while (i < H)
	{
		mlx_put_pixel_to_image(i, x, 0x3A1413, wolf->mlx);
		++i;
	}
}

int				expose_hook(t_wolf *wolf)
{
	if (wolf->map->status)
	{
		ray_casting(wolf);
		mlx_put_image_to_window(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr,
			wolf->mlx->img_ptr, 0, 0);
		info(wolf);
		fps(wolf);
		if (wolf->keys->up_down)
			move_up_down(wolf);
		if (wolf->keys->left_right)
			move_left_right(wolf);
		if (wolf->keys->rotate == 1)
			move_rotate_left(wolf);
		if (wolf->keys->rotate == -1)
			move_rotate_right(wolf);
	}
	return (0);
}
