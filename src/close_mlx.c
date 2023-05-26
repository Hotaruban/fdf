/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:34:27 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/27 02:16:07 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The key_hook close the window when the ESC key is pressed.
*/

int	key_hook(int keycode, t_data *sdata)
{
	if (keycode == 53)
	{
		free_2d_array(sdata->map, sdata->size.row);
		mlx_destroy_image(sdata->mlx.mlx_ptr, sdata->mlx.img_ptr);
		mlx_destroy_window(sdata->mlx.mlx_ptr, sdata->mlx.win_ptr);
		exit(0);
	}
	return (0);
}

/*
The loop_hook close the window when the red cross is pressed.
*/

int	loop_hook(t_data *sdata)
{
	(void)sdata;
	exit(0);
}
