/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 19:56:35 by vholovin          #+#    #+#             */
/*   Updated: 2017/07/20 18:16:47 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	fps(t_wolf *wolf)
{
	static int		timestamp;
	static int		fps;

	if (time(NULL) != timestamp)
	{
		wolf->mlx->fps = fps;
		fps = 0;
		timestamp = (int)time(NULL);
	}
	else
		fps++;
	if (wolf->mlx->fps > 1)
	{
		wolf->player->speed_move = 3.0 / wolf->mlx->fps * wolf->keys->speed;
		wolf->player->speed_rotate = 1.5 / wolf->mlx->fps * wolf->keys->speed;
	}
	else
	{
		wolf->player->speed_move = 0.2;
		wolf->player->speed_rotate = 0.1;
	}
}
