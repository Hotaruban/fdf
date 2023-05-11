/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:51:50 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/12 01:13:09 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 900
# define WIN_HEIGHT 900
# define WIN_NAME "FDF"

typedef struct s_pixel
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_pixel;

typedef struct s_map
{
	int			rows;
	int			columns;
}				t_map;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_mlx;

int	main(int ac, char **av);

/*MAP*/
void	count_rows_columns_map(t_map map, char *map);
int	count_columns_map(char *line);

/*MLX*/
void	open_mlx();
int		key_hook(int keycode, t_mlx *display);
void	loop_hook(t_mlx *display);

/*ERROR*/
int	check_error_extension(char *map);


#endif
