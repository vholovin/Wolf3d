/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 17:23:07 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/08 18:40:52 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		main(void)
{
	t_wolf *wolf;

	tutorial();
	wolf = init_wolf();
	if (wolf->map->status == 1)
	{
		mlx_hook(wolf->mlx->win_ptr, 2, 1L << 0, key_press, wolf);
		mlx_hook(wolf->mlx->win_ptr, 3, 1L << 0, key_hook, wolf);
		mlx_hook(wolf->mlx->win_ptr, 17, 1L << 17, esc, wolf);
		mlx_loop_hook(wolf->mlx->mlx_ptr, expose_hook, wolf);
	}
	mlx_loop(wolf->mlx->mlx_ptr);
	return (0);
}
