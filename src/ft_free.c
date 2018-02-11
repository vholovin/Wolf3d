/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 13:57:41 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:48:08 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		ft_free_map(t_wolf *wolf)
{
	size_t	i;

	i = 0;
	while (i < wolf->map->height)
	{
		free(wolf->map->array[i]);
		++i;
	}
	free(wolf->map->array);
	free(wolf->map);
}

static void		ft_free_texture(t_wolf *wolf)
{
	int i;

	i = 0;
	while (i < K_T)
	{
		free(wolf->texture[i].img_ptr);
		free(wolf->texture[i].ptr);
		i++;
	}
}

static void		ft_free_mlx(t_wolf *wolf)
{
	mlx_destroy_image(wolf->mlx->mlx_ptr, wolf->mlx->img_ptr);
	mlx_destroy_window(wolf->mlx->mlx_ptr, wolf->mlx->win_ptr);
	free(wolf->mlx->mlx_ptr);
	free(wolf->mlx);
}

void			ft_free(t_wolf *wolf)
{
	ft_free_texture(wolf);
	free(wolf->player);
	free(wolf->keys);
	free(wolf->rays);
	ft_free_map(wolf);
	ft_free_mlx(wolf);
	free(wolf);
}
