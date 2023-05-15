/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:20:00 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/14 03:09:43 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx/mlx.h"
#include "../libft/includes/libft.h"

void	open_mlx()
{
	t_data3	display;

	display.mlx_ptr = mlx_init();
	display.win_ptr = mlx_new_window(display.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	display.img_ptr = mlx_new_image(display.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx_put_image_to_window(display.mlx_ptr, display.win_ptr, display.img_ptr, 0, 0);
	mlx_key_hook(display.win_ptr, key_hook, &display);
	mlx_hook(display.win_ptr, 17, 0, loop_hook, &display);
	mlx_loop(display.mlx_ptr);
}
