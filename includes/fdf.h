/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:58 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/18 01:17:35 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define WIN_NAME "FDF"

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

typedef struct s_mothers
{
	t_map	**map;
	t_size	size;
}				t_mothers;

# define MMAP mothership.map
# define MSIZE mothership.size

/*
Function to check errors or exit.
*/
void		exit_error(char *str);
void		exit_error_2d_arrays(t_map **ptr, int i, char *str);
void		exit_free_close_fd(void *ptr, int fd, char *str);
void	exit_close_fd(int fd, char *str);
static void	check_error_extension(char *map);
static void check_error_size_map(t_size size);

/*
Functions to count the number of rows and columns.
*/
void		count_rows_columns(t_size *map_size, char *file);
static void	count_rows(t_size *map_size, int fd);
static int	count_columns(char *line);

/*
Function to creat the array of struct and initialize it.
*/
t_map		**creat_struct_map(t_size size, t_map **map);
void		free_2d_array(t_map **ptr, int i);
void	get_z_data(t_mothers mothership, char *file);
static void	copy_z_data(t_mothers mothership, char **str, int i, int fd);
static int	check_int_hex(char *str);
static int	check_hexa(char *str);
static int	check_int(char *str, char c);
void		free_null_2d_array(char **ptr);

#endif
