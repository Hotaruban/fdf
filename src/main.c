/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:32:00 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/27 01:56:11 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The check_error_extension checks if the extension of the map is valid.
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
The check_error_size_map checks if the size of the map is valid.
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
	t_data		sdata;

	if (ac != 2)
	{
		perror("Error: no files provide!\n");
		exit(1);
	}
	check_error_extension(av[1]);
	count_rows_columns(&sdata.size, av[1]);
	check_error_size_map(sdata.size);
	sdata.map = creat_struct_map(sdata.size, sdata.map);
	get_z_data(sdata, av[1]);
	open_mlx(&sdata);
	free_2d_array(sdata.map, sdata.size.row);
}
