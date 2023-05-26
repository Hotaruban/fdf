/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:34:27 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/26 16:16:01 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mlx_math.h"

/*
The function key_hook close the window when the ESC key is pressed.
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
The function loop_hook close the window when the red cross is pressed.
*/

int	loop_hook(t_data *sdata)
{
	exit(0);
}
