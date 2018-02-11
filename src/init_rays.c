/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:20:20 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/08 18:40:21 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

t_rays	*init_rays(t_wolf *wolf)
{
	t_rays	*rays;

	if (!(rays = (t_rays*)malloc(sizeof(t_rays))))
		error(0, wolf);
	rays->position_x = 0;
	rays->position_y = 0;
	rays->map_x = 0;
	rays->map_y = 0;
	rays->camera_x = 0;
	rays->direction_x = 0;
	rays->direction_y = 0;
	rays->delta_dist_x = 0;
	rays->delta_dist_y = 0;
	rays->perp_wall_dist = 0;
	rays->hit = 0;
	rays->side = 0;
	rays->step_x = 0;
	rays->step_y = 0;
	rays->side_x = 0;
	rays->side_y = 0;
	rays->line_height = 0;
	return (rays);
}
