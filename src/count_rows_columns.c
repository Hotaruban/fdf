/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rows_columns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:49:00 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/29 03:30:38 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The count_columns count the number of columns of a line.
*/

static int	count_columns(char *line)
{
	int	word_count;
	int	in_word;

	word_count = 0;
	in_word = 0;
	while (*line && *line != '\n')
	{
		if (*line == ' ')
			in_word = 0;
		else if (!in_word)
		{
			word_count++;
			in_word = 1;
		}
		line++;
	}
	return (word_count);
}

/*
The count_rows count the number of rows of the map.
*/

static void	count_rows(t_size *map_size, int fd)
{
	char	*ptr;

	ptr = get_next_line(fd);
	if (ptr == NULL)
		exit_close_fd(fd, "Error: empty file!\n");
	map_size->col = count_columns(ptr);
	map_size->row = 0;
	while (ptr != NULL)
	{
		free(ptr);
		map_size->row++;
		ptr = get_next_line(fd);
		if (ptr == NULL)
			break ;
		if (map_size->col != count_columns(ptr))
			exit_free_close_fd(ptr, fd, "Error: unvalid size of map!\n");
	}
	close(fd);
}

/*
The count_rows_columns count the number of rows and columns of the map.
*/

void	count_rows_columns(t_size *map_size, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: impossible to open the file");
		exit(1);
	}
	count_rows(map_size, fd);
}
