/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:32:58 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/26 04:53:23 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_math.h"

static void	get_scale(t_data *sdata)
{
	sdata->size.scale = 0;
	if ((sdata->size.row + 2) < (sdata->size.col + 2))
		sdata->size.scale = WIN_HEIGHT / (sdata->size.row * 2);
	else
		sdata->size.scale = WIN_WIDTH / (sdata->size.col * 2);
}

void	scale_map(t_data *sdata)
{
	int	i;
	int	j;

	get_scale(sdata);
	i = 0;
	while (i < sdata->size.row)
	{
		j = 0;
		while (j < sdata->size.col)
		{
			sdata->map[i][j].x *= sdata->size.scale;
			sdata->map[i][j].y *= sdata->size.scale;
			j++;
		}
		i++;
	}
}
