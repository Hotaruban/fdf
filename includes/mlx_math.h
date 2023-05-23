/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:52:42 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/23 16:47:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MATH_H
# define MLX_MATH_H
# include "./struct.h"
# include "../mlx/mlx.h"
# include <unistd.h>


# define WIN_WIDTH 1350
# define WIN_HEIGHT 900
# define WIN_NAME "FDF"

/*
Function to open and close the window
*/
void		open_mlx(t_data *sdata);
int			key_hook(int keycode, t_data *sdata);
int			loop_hook(t_data *sdata);

/*
Function to creat and put image
*/
void		*creat_img(t_data *sdata);
void		my_mlx_pixel_put(t_data *sdata, int x, int y, int color);
void		scale_map(t_data *sdata);
static int	get_scale_map(t_data *sdata);

#endif
