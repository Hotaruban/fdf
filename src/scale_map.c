/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:39:41 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/23 16:53:14 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_math.h"

/*
The function get_scale_map returns the scale of the map. The calculation is
based on the size of the window and the size of the map.
*/

static int	get_scale_map(t_data *sdata)
{
	int	scale;

	scale = 0;
	if (sdata->size.row > sdata->size.col)
		scale = WIN_HEIGHT / (sdata->size.row + 2);
	else
		scale = WIN_WIDTH / (sdata->size.col + 2);
	return (scale);
}

void		scale_map(t_data *sdata)
{
	int	scale_x;
	int	scale_y;
	int	i;
	int	j;

	scale_x = get_scale_map(sdata);
	scale_y = scale_x;
	i = 0;
	while (i < sdata->size.row)
	{
		j = 0;
		while (j < sdata->size.col)
		{
			sdata->map[i][j].x *= scale_x;
			sdata->map[i][j].y *= scale_y;
			j++;
		}
		i++;
	}
}
