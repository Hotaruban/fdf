/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:34:27 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/27 01:06:49 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mlx_math.h"

/*
The key_hook close the window when the ESC key is pressed.
*/

int	key_hook(int keycode, t_data *sdata)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

/*
The loop_hook close the window when the red cross is pressed.
*/

int	loop_hook(t_data *sdata)
{
	exit(0);
}
