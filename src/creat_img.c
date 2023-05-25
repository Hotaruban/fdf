/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:04:49 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/26 04:53:00 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_math.h"

void	my_mlx_pixel_put(t_data *sdata, int x, int y, int color)
{
	char	*dst;

	dst = sdata->img.addr + (y * sdata->img.line_length + x
		* (sdata->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	display_map(t_data *sdata)
{
	//int	i;
	//int	j;

	scale_map(sdata);
	convert_iso(sdata);
	draw_row(sdata);
	draw_col(sdata);
	//i = -1;
	//while (++i < sdata->size.row)
	//{
	//	j = -1;
	//	while (++j < sdata->size.col)
	//	{
	//		my_mlx_pixel_put(sdata, sdata->map[i][j].x,
	//			sdata->map[i][j].y, sdata->map[i][j].color);
	//	}
	//}
}

void		*creat_img(t_data *sdata)
{
	sdata->mlx.img_ptr = mlx_new_image(sdata->mlx.mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT);
	sdata->img.addr = mlx_get_data_addr(sdata->mlx.img_ptr,
		&sdata->img.bits_per_pixel, &sdata->img.line_length,
		&sdata->img.endian);
	display_map(sdata);
	return (sdata->mlx.img_ptr);
}
