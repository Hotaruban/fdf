/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:58:41 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/23 13:40:53 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_map;

typedef struct s_size
{
	int	width_img;
	int	height_img;
	int	row;
	int	col;
}			t_size;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
}			t_mlx;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	t_map	**map;
	t_size	size;
	t_mlx	mlx;
	t_img	img;
}				t_data;

#endif
