/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_struct_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:30:37 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/12 01:09:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"

/*
The function creat_struct_map creat a array of struct*/

t_pixel	**creat_struct_map(t_map map) // creat a array of struct
{
	t_pixel			**map_struct;
	int				i;

	i = 0;
	map_struct = (t_pixel **)malloc(sizeof(t_pixel *) * map.rows);
	while (i < map.rows)
	{
		map_struct[i] = (t_pixel *)malloc(sizeof(t_pixel) * map.columns);
		i++;
	}
	return (map_struct);
}
