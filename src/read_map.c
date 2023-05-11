/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:05:05 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/12 01:08:05 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include "./includes/libft.h"

void	count_rows_columns_map(t_map map, char *map) // count the number of rows and columns of the map
{
	char	*ptr;
	int		fd;

	fd = open(map, O_RDONLY)
	if (fd == -1)
		return (NULL);
	ptr = get_next_line(fd);
	map->columns = count_columns_map(ptr); // get the number of columns of the first line
	while(ptr != NULL)
	{
		free(ptr);
		map->rows++;
		ptr = get_next_line(fd);
		if (map->columns != count_columns_map(ptr)) // check if the number of columns is the same for each line
		{
			free(ptr);
			close(fd);
			break ; // map error to handle with ERROR message
		}
	}
	close(fd);
}

int	count_columns_map(char *line) // count the number of columns of a line
{
	int	i;
	int	columns;

	i = 0;
	columns = 0;
	while (line[i] != '\n')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ')
		{
			columns++;
			while (line[i] != ' ')
				i++;
		}
	}
	return (columns);
}

