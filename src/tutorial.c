/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:01:24 by vholovin          #+#    #+#             */
/*   Updated: 2017/07/20 18:46:41 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	tutorial(void)
{
	ft_putstr("\
CONTROLS:\n\
Move:\n\
	Up:             Key: w\n\
	Down:           Key: s\n\
	Left:           Key: q\n\
	Righ:           Key: e\n\
	Speed:          Key: shift\n\
Rotate:\n\
	Left:           Key: a\n\
	Right:          Key: d\n\
Zoom:\n\
	Zoom +:         Key: +\n\
	Zoom -:         Key: -\n\
Map:\n\
	Choose map:     Key: 1-3\n\
	Choose color:   Key: ~\n\
\n\
	Exit:           Key: esc\n\
");
}
