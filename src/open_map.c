/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:49:09 by vholovin          #+#    #+#             */
/*   Updated: 2017/08/09 14:48:06 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		free_split(char **line_split)
{
	size_t i;

	i = 0;
	while (line_split[i] != '\0')
	{
		free(line_split[i]);
		++i;
	}
	free(line_split);
}

static void		read_status(int fd, t_wolf *wolf)
{
	char	*line;
	char	**line_split;
	size_t	i;

	if (get_next_line(fd, &line) < 1)
		error(1, wolf);
	line_split = ft_strsplit(line, ' ');
	free(line);
	i = 0;
	while (line_split[i] != '\0')
		++i;
	if (i != 4)
		error(2, wolf);
	wolf->map->height = ft_atoi(line_split[0]);
	wolf->map->width = ft_atoi(line_split[1]);
	wolf->player->position_y = ft_atoi(line_split[2]) + 0.5;
	wolf->player->position_x = ft_atoi(line_split[3]) + 0.5;
	if (wolf->map->width <= 0 || wolf->map->height <= 0)
		error(2, wolf);
	if (wolf->player->position_x < 0 || wolf->player->position_y < 0 ||
		wolf->player->position_x >= wolf->map->width ||
		wolf->player->position_y >= wolf->map->height)
		error(3, wolf);
	free_split(line_split);
}

static void		read_line(char *line, size_t y, int **array, t_wolf *wolf)
{
	size_t	x;
	char	**line_split;

	array[y] = (int*)malloc(sizeof(int) * wolf->map->width + 1);
	x = 0;
	line_split = ft_strsplit(line, ' ');
	while (line_split[x] != '\0')
	{
		if (ft_isalpha(line_split[x][0]))
			error(2, wolf);
		array[y][x] = ft_atoi(line_split[x]);
		if ((x == 0 || x == wolf->map->width - 1 ||
			y == 0 || y == wolf->map->height - 1) && array[y][x] == 0)
			error(2, wolf);
		++x;
	}
	free(line);
	free_split(line_split);
	if (x != wolf->map->width)
		error(2, wolf);
}

static void		read_map(int fd, t_wolf *wolf)
{
	size_t	y;
	int		**array;
	char	*line;

	array = (int**)malloc(sizeof(int *) * wolf->map->height + 1);
	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		read_line(line, y, array, wolf);
		++y;
	}
	if (y != wolf->map->height)
		error(2, wolf);
	wolf->map->array = array;
}

void			open_map(t_wolf *wolf)
{
	int		fd;

	wolf->map->status = 0;
	fd = open(wolf->map->name, O_DIRECTORY);
	if (fd >= 0)
		error(1, wolf);
	fd = open(wolf->map->name, O_RDONLY);
	if (fd < 0)
		error(1, wolf);
	read_status(fd, wolf);
	read_map(fd, wolf);
	if (wolf->map->array[(int)wolf->player->position_y]
		[(int)wolf->player->position_x] != 0)
		error(3, wolf);
	wolf->map->status = 1;
}
