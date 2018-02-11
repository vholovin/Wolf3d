/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:20:52 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/08 18:41:03 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		init_2(t_wolf *wolf)
{
	wolf->texture[3].pixel_size = 1024;
	wolf->texture[3].img_ptr = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
		"textures/wood.xpm", &wolf->texture[3].pixel_size,
		&wolf->texture[3].pixel_size);
	wolf->texture[3].ptr = mlx_get_data_addr(wolf->texture[3].img_ptr,
		&wolf->texture[3].bits_per_pixel, &wolf->texture[3].size_line,
		&wolf->texture[3].endian);
	wolf->texture[4].pixel_size = 1024;
	wolf->texture[4].img_ptr = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
		"textures/metal.xpm", &wolf->texture[4].pixel_size,
		&wolf->texture[4].pixel_size);
	wolf->texture[4].ptr = mlx_get_data_addr(wolf->texture[4].img_ptr,
		&wolf->texture[4].bits_per_pixel, &wolf->texture[4].size_line,
		&wolf->texture[4].endian);
}

static void		init_1(t_wolf *wolf)
{
	wolf->texture[1].pixel_size = 1024;
	wolf->texture[1].img_ptr = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
		"textures/brick.xpm", &wolf->texture[1].pixel_size,
		&wolf->texture[1].pixel_size);
	wolf->texture[1].ptr = mlx_get_data_addr(wolf->texture[1].img_ptr,
		&wolf->texture[1].bits_per_pixel, &wolf->texture[1].size_line,
		&wolf->texture[1].endian);
	wolf->texture[2].pixel_size = 1024;
	wolf->texture[2].img_ptr = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
		"textures/grass.xpm", &wolf->texture[2].pixel_size,
		&wolf->texture[2].pixel_size);
	wolf->texture[2].ptr = mlx_get_data_addr(wolf->texture[2].img_ptr,
		&wolf->texture[2].bits_per_pixel, &wolf->texture[2].size_line,
		&wolf->texture[2].endian);
}

void			init_texture(t_wolf *wolf)
{
	wolf->texture[0].pixel_size = 1024;
	wolf->texture[0].img_ptr = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
		"textures/stone.xpm", &wolf->texture[0].pixel_size,
		&wolf->texture[0].pixel_size);
	wolf->texture[0].ptr = mlx_get_data_addr(wolf->texture[0].img_ptr,
		&wolf->texture[0].bits_per_pixel, &wolf->texture[0].size_line,
		&wolf->texture[0].endian);
	init_1(wolf);
	init_2(wolf);
}
