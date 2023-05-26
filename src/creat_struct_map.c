/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_struct_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:56:09 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/27 00:58:29 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The creat_struct_map creat an array of struct to save the map.
*/

t_map	**creat_struct_map(t_size size, t_map **map)
{
	int	i;
	int	j;

	map = (t_map **)malloc(sizeof(t_map *) * size.row);
	if (map == NULL)
		exit_error("Error: malloc error!\n");
	i = 0;
	j = 0;
	while (i < size.row)
	{
		map[i] = (t_map *)malloc(sizeof(t_map) * size.col);
		if (map[i] == NULL)
			exit_error_2d_arrays(map, i, "Error: malloc error!\n");
		while (j < size.col)
		{
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].color = 16777215;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}
