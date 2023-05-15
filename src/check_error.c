/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:40:31 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/15 01:07:43 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"

/*
The function check_error_extension() checks if the map has a .fdf extension.
*/

int	check_error_extension(char *map)
{
	int		len;

	len = ft_strlen(map) - 4;
	if (len < 0)
		return (1); // ERROR message to handle
	if (ft_strncmp(&map[len], ".fdf", 4) != 0)
		return (1); // ERROR message to handle
	return (0);
}

/*
The function check_error_data() checks if the data in the map are valid.
*/

int	check_error_data(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] && fd != -1)
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i += 2;
		else if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		{
			i += 3;
			while (ft_ishexa(str[i]))
				i++;
		}
		else
		{
			free(str);
			close(fd);
			perror("Error: invalid data");
			return (1);
		}
	}
	return (0);
}
