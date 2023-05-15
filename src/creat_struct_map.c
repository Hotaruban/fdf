/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_struct_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:30:37 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/15 12:29:11 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"

/*
The function init_x_y_color initialize the x, y and color of each struct.
*/

static void	init_x_y_color(t_data1 **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			(*map)[i][j].x = i;
			(*map)[i][j].y = j;
			(*map)[i][j].color = 16777215;
			j++;
		}
		j = 0;
		i++;
	}
}

/*
The function creat_struct_map creat a array of struct to save the map.
*/

t_data1	**creat_struct_map(t_data2 map_file) // creat a array of struct
{
	t_data1	**map;
	int		i;
	int		j;

	i = 0;
	map = (t_data1 **)malloc(sizeof(t_data1 *) * (map_file.rows + 1));
	if (!map)
		return (NULL); // ERROR message to handle (malloc error) do not forget to free
	map[map_file.rows] = NULL;
	while (i < map.rows)
	{
		map[i] = (t_data1 *)malloc(sizeof(t_data1) * (map_file.columns + 1));
		if (!map[i])
		{
			free_2d_array(map);
			return (NULL); // ERROR message to handle (malloc error) do not forget to free
		}
		map[i][map_file.columns] = NULL;
		i++;
	}
	init_xy_struct(map);
	return (map);
}

/*
The function creat_map creat a array of struct to save the map.
*/

t_data1	**creat_map(char *file)
{
	t_data1	**map;
	t_data2	map_file;

	count_rows_columns(&map_file, file);
	map = create_struct_map(map_file);

	return (map);
}
