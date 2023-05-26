/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:26:11 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/27 02:16:21 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_math.h"

/*
The draw_row and draw_col draw a row or a column of the map.
*/

static void	dda_coordinate(t_point node_1, t_point node_2, t_data *sdata)
{
	sdata->size.dx = (node_2.x - node_1.x);
	sdata->size.dy = (node_2.y - node_1.y);
	if (sdata->size.dx >= sdata->size.dy)
		sdata->size.step = sdata->size.dx;
	else
		sdata->size.step = sdata->size.dy;
	sdata->size.dx = sdata->size.dx / sdata->size.step;
	sdata->size.dy = sdata->size.dy / sdata->size.step;
}

static void	dda_draw_line(t_point node_1, t_point node_2, t_data *sdata)
{
	float	x;
	float	y;
	int		i;

	dda_coordinate(node_1, node_2, sdata);
	x = node_1.x;
	y = node_1.y;
	i = 0;
	while (i <= sdata->size.step)
	{
		my_mlx_pixel_put(sdata, y, x, node_1.color);
		x += sdata->size.dx;
		y += sdata->size.dy;
		i++;
	}
}

void	draw_row(t_data *sdata)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sdata->size.row)
	{
		j = -1;
		while (++j < sdata->size.col - 1)
		{
			sdata->node_1.x = sdata->map[i][j].y;
			sdata->node_1.y = sdata->map[i][j].x;
			sdata->node_1.color = sdata->map[i][j].color;
			sdata->node_2.x = sdata->map[i][j + 1].y;
			sdata->node_2.y = sdata->map[i][j + 1].x;
			sdata->node_2.color = sdata->map[i][j + 1].color;
			dda_draw_line(sdata->node_1, sdata->node_2, sdata);
		}
	}
}

void	draw_col(t_data *sdata)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sdata->size.row - 1)
	{
		j = -1;
		while (++j < sdata->size.col)
		{
			sdata->node_1.x = sdata->map[i][j].y;
			sdata->node_1.y = sdata->map[i][j].x;
			sdata->node_1.color = sdata->map[i][j].color;
			sdata->node_2.x = sdata->map[i + 1][j].y;
			sdata->node_2.y = sdata->map[i + 1][j].x;
			sdata->node_2.color = sdata->map[i + 1][j].color;
			dda_draw_line(sdata->node_1, sdata->node_2, sdata);
		}
	}
}
