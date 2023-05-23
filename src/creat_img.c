/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:04:49 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/23 16:46:56 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_math.h"

void		my_mlx_pixel_put(t_data *sdata, int x, int y, int color)
{
	char	*dst;

	dst = sdata->img.addr + (y * sdata->img.line_length + x * (sdata->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		*creat_img(t_data *sdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	sdata->mlx.img_ptr = mlx_new_image(sdata->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	sdata->img.addr = mlx_get_data_addr(sdata->mlx.img_ptr, &sdata->img.bits_per_pixel, &sdata->img.line_length, &sdata->img.endian);
	scale_map(sdata);
	while (i < sdata->size.row)
	{
		j = 0;
		while (j < sdata->size.col)
		{
			my_mlx_pixel_put(sdata, sdata->map[i][j].x, sdata->map[i][j].y, sdata->map[i][j].color);
			j++;
		}
		i++;
	}
	return (sdata->mlx.img_ptr);
}
