/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rows_columns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:05:05 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/15 12:37:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include "./includes/libft.h"

/*
The function count_columns count the number of columns of a line.
*/

static int	count_columns(char *line)
{
	int		i;
	int		columns;

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

/*
The function count_rows count the number of rows of the map.
*/

static void	count_rows(t_data2 map_file, int fd)
{
	char	*ptr;

	ptr = get_next_line(fd);
	if (check_error_data(ptr, fd))
		exit(1);
	map_file->len_columns = count_columns(ptr);
	map_file->len_rows = 1;
	while(ptr != NULL)
	{
		free(ptr);
		map_file->len_rows++;
		ptr = get_next_line(fd);
		if (check_error_data(ptr, fd))
			exit(1);
		if (map_file->len_columns != count_columns(ptr))
		{
			free(ptr);
			close(fd);
			perror("Error: file is not a valid map");
			exit(1);
		}
	}
	close(fd);
}

/*
The function count_rows_columns count the number of rows and columns of the map.
*/

void	count_rows_columns(t_data2 map_file, char *file)
{
	char	*ptr;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: impossible to open the file");
		exit(1);
	}
	count_rows(map_file, fd);
}
