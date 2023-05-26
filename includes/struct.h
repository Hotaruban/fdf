/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:58:41 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/26 16:21:11 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_map;

typedef struct s_size
{
	int		row;
	int		col;
	float	scale;
	float	cen_x;
	float	cen_y;
	float	dx;
	float	dy;
	float	step;
}			t_size;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
}			t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}			t_point;

typedef struct s_data
{
	t_map	**map;
	t_size	size;
	t_mlx	mlx;
	t_img	img;
	t_point	node_1;
	t_point	node_2;
}				t_data;

#endif
