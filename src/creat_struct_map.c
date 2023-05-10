/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_struct_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:09:45 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/10 09:54:14 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include "./includes/libft.h"

/*
The extract_map_lines function takes a file path as input and reads
the contents of the file. The function reads each line of the file using
get_next_line and appends it to a dynamically allocated 2D array using
realloc_2d_array to expand the size of the array as needed.
The function returns a pointer to the resulting 2D array containing
the contents of the file, or NULL if there was an error opening
or reading the file. The number of lines read from the file is stored
in the integer pointed to by lines. If no lines were read,
lines will be set to 0.
*/

static char	**extract_map_lines(char *map, int *lines)
{
	int		fd;
	int		i;
	char	**ptr;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	ptr = (char **)malloc(sizeof(char *) * 1);
	if (ptr == NULL)
	{
		close(fd);
		return (NULL);
	}
	while (1)
	{
		ptr[i] = get_next_line(fd);
		realloc_2d_array(ptr, i + 1, i + 2);
		if (ptr[i] == NULL)
			break ;
		i++;
	}
	ptr[i] = NULL;
	*lines = i;
	close(fd);
	return (ptr);
}

// function who will split and count the amount of string in the array of lines

static char	***split_and_count(char **ptr_read_map, int lines, int *columns)
{
	char	***ptr;
	int		i;

	ptr = (char ***)malloc(sizeof(char **) * (lines + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[lines] = NULL;
	i = 0;
	while (i < lines)
	{
		ptr[i] = ft_split(ptr_read_map[i], ' ');
		if (i == 0)
			*columns = ft_strlen(ptr[0]);
		if (*columns != ft_strlen(ptr[i]) && i != 0)
		{
			free_2d_array((void **)ptr, i);
			free(ptr);
			return (NULL);
		}
		i++;
	}
	return (ptr);
}

// function will creat a array of struct and return a pointer of this array

char	*create_struct_array(char *map)
{
	char	**ptr_read_map;
	char	***ptr_split_map;
	int		*lines;
	int		*columns;

	lines = 0;
	ptr_read_map = extract_map_lines(map, lines);
	if (ptr_read_map == NULL)
		return (NULL);
	columns = 0;
	ptr_split_map = split_and_count(ptr_read_map, lines, columns);

}

