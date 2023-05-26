/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:58 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/27 02:01:20 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./struct.h"
# include "./mlx_math.h"
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

/*
Function to check errors or exit.
*/
void		exit_error(char *str);
void		exit_error_2d_arrays(t_map **ptr, int i, char *str);
void		exit_free_close_fd(void *ptr, int fd, char *str);
void		exit_close_fd(int fd, char *str);

/*
Function to creat the array of struct and initialize it.
*/
t_map		**creat_struct_map(t_size size, t_map **map);
void		count_rows_columns(t_size *map_size, char *file);
void		free_2d_array(t_map **ptr, int i);
void		get_z_data(t_data sdata, char *file);
void		free_null_2d_array(char **ptr);

#endif
