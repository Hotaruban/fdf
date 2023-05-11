/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:20:00 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/12 01:07:23 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx/mlx.h"
#include "../libft/includes/libft.h"

int		key_hook(int keycode, t_mlx *display) // close the window when ESC is pressed
{
	if (keycode == 53)
	{
		mlx_destroy_window(display->mlx_ptr, display->win_ptr);
		exit(0);
	}
	return (0);
}

void	loop_hook(t_mlx *display)
{
	exit(0);
}

void	open_mlx()
{
	t_mlx	display;

	display.mlx_ptr = mlx_init();
	display.win_ptr = mlx_new_window(display.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	display.img_ptr = mlx_new_image(display.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);

	mlx_put_image_to_window(display.mlx_ptr, display.win_ptr, display.img_ptr, 0, 0);
	mlx_key_hook(display.win_ptr, key_hook, &display);
	//mlx_loop_hook(display.mlx_ptr, loop_hook, &display);
	mlx_loop(display.mlx_ptr);
}
