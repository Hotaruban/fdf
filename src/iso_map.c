/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:30:23 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/26 16:19:27 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_math.h"

static void	get_center(int x, int y, t_data *sdata)
{
	float	size_col;
	float	size_row;

	x = (float)(WIN_WIDTH / 2);
	y = (float)(WIN_HEIGHT / 2);
	size_col = (float)((sdata->size.col * sdata->size.scale) / 2);
	size_row = (float)((sdata->size.row * sdata->size.scale) / 2);
	sdata->size.cen_x = x - (size_col - size_row) * cos(.523599);
	sdata->size.cen_y = y - (size_col + size_row) * sin(.523599);
}

static void	center_point(int x, int y, t_map *map)
{
	map->x = (x - y) * cos(.523599);
	map->y = ((x + y) * sin(.523599)) - map->z;
}

void	convert_iso(t_data *sdata)
{
	int		i;
	int		j;

	get_center(sdata->size.cen_x, sdata->size.cen_y, sdata);
	i = -1;
	while (++i < sdata->size.row)
	{
		j = -1;
		while (++j < sdata->size.col)
		{
			center_point(sdata->map[i][j].x, sdata->map[i][j].y,
				&sdata->map[i][j]);
			sdata->map[i][j].x += sdata->size.cen_x;
			sdata->map[i][j].y += sdata->size.cen_y;
		}
	}
}
