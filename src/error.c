/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:41:47 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/08 18:29:09 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	error(int status, t_wolf *wolf)
{
	if (status == 0)
		ft_putendl("error maloc");
	if (status == 1)
		ft_putendl("error open map");
	if (status == 2)
		ft_putendl("error read map");
	if (status == 3)
		ft_putendl("error position");
	wolf->map->status = 0;
	exit(0);
}
