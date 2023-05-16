/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_struct_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:56:09 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/17 00:54:50 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The function creat_struct_map creat an array of struct to save the map.
*/

/*
ERROR message to handle (malloc error)
*/

t_map	**creat_struct_map(t_size size, t_map **map)
{
	int		i;
	int		j;

	map = (t_map **)malloc(sizeof(t_map *) * size.row);
	if (map == NULL)
		exit (0);
	i = 0;
	j = 0;
	while (i < size.row)
	{
		map[i] = (t_map *)malloc(sizeof(t_map) * size.col);
		if (map[i] == NULL)
			free_2d_array(map, i);
		while (j < size.col)
		{
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].color = 16777215;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}
