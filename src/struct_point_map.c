/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_point_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:32:00 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/17 23:42:06 by jhurpy           ###   ########.fr       */
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
	t_size	size;
	t_map	**map;
	int		i;
	int		j;

	check_error_extension(av[1]);
	count_rows_columns(&size, av[1]);
	check_error_size_map(size);
	map = creat_struct_map(size, map);
	get_z_data(map, size, av[1]);
	i = 0;
	//while (i < size.row)
	//{
	//	j = 0;
	//	while (j < size.col)
	//	{
	//		printf("[x = %d], [y = %d], [z = %d], [color = %d]\n", map[i][j].x, map[i][j].y, map[i][j].z, map[i][j].color);
	//		j++;
	//	}
	//	i++;
	//}
	free_2d_array(map, size.row);
}
