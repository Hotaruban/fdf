/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_point_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:32:00 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/18 01:21:25 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The function check_error_extension checks if the extension of the map is valid.
*/

static void	check_error_extension(char *map)
{
	int		len;

	len = ft_strlen(map) - 4;
	if (len < 0)
	{
		perror("Error: unvalid extension of map!\n");
		exit(1);
	}
	if (ft_strncmp(&map[len], ".fdf", 4) != 0)
	{
		perror("Error: unvalid extension of map!\n");
		exit(1);
	}
}

/*
The function check_error_size_map checks if the size of the map is valid.
*/

static void	check_error_size_map(t_size size)
{
	if (size.row < 2 || size.col < 2)
	{
		perror("Error: unvalid size of map!\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_mothers	mothership;
	int			i;
	int			j;

	if (ac != 2)
	{
		perror("Error: no files provide!\n");
		exit(1);
	}
	check_error_extension(av[1]);
	count_rows_columns(&MSIZE, av[1]);
	check_error_size_map(MSIZE);
	MMAP = creat_struct_map(MSIZE, MMAP);
	get_z_data(mothership, av[1]);
	i = 0;
	while (i < MSIZE.row)
	{
		j = 0;
		while (j < MSIZE.col)
		{
			printf("[x = %d], [y = %d], [z = %d], [color = %d]\n", MMAP[i][j].x, MMAP[i][j].y, MMAP[i][j].z, MMAP[i][j].color);
			j++;
		}
		i++;
	}
	free_2d_array(MMAP, MSIZE.row);
}
