/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:51:50 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/15 12:36:46 by jhurpy           ###   ########.fr       */
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

typedef struct s_data1
{
	int			x;
	int			y;
	int			z;
	int			color;
	t_data2		*file;
}				t_data1;

typedef struct s_data2
{
	int			len_rows;
	int			len_columns;
}				t_data2;

typedef struct s_data3
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_data3;

int	main(int ac, char **av);

/*MAP*/
void	count_rows_columns(t_data2 map, char *map);
int		count_columns(char *line);

/*MLX*/
void	open_mlx();
int		key_hook(int keycode, t_data3 *display);
void	loop_hook(t_data3 *display);

/*ERROR*/
int		check_error_extension(char *map);
int		check_error_data(char *ptr);

#endif
