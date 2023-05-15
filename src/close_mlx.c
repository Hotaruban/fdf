/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:34:27 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/12 08:41:19 by jhurpy           ###   ########.fr       */
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
