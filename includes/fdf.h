/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:51:50 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/10 03:43:24 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define WIN_NAME "FDF"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

/*
Main functions
*/

char	*create_struct_array(char *map);

/*
Error functions
*/

/*
Utilitaries functions
*/

void	realloc_2d_array(char ***ptr, size_t old_size, size_t new_size);

/*
Free functions
*/

void	free_2d_array(void **ptr, int i);

#endif
