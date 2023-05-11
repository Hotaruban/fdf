/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:40:31 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/12 00:47:54 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"


//int	check_error_map()
//{

//}

int	check_error_extension(char *map) // check if the map has a .fdf extension
{
	int		len;

	len = ft_strlen(map) - 4;
	if (len < 0)
		return (1); // ERROR message to handle
	if (ft_strncmp(&map[len], ".fdf", 4) != 0)
		return (1); // ERROR message to handle
	return (0);
}

//int	check_error_data_map()
//{

//}
