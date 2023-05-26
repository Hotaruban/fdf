/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:20:00 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/27 00:56:34 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_math.h"

/*
The open_mlx opens a window and displays the image.
*/

void	open_mlx(t_data *sdata)
{
	sdata->mlx.mlx_ptr = mlx_init();
	sdata->mlx.win_ptr = mlx_new_window(sdata->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	sdata->mlx.img_ptr = creat_img(sdata);
	mlx_put_image_to_window(sdata->mlx.mlx_ptr,
		sdata->mlx.win_ptr, sdata->mlx.img_ptr, 0, 0);
	mlx_key_hook(sdata->mlx.win_ptr, key_hook, &sdata);
	mlx_hook(sdata->mlx.win_ptr, 17, 0, loop_hook, &sdata);
	mlx_loop(sdata->mlx.mlx_ptr);
}
