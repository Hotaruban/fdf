/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:11:27 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/17 18:55:20 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	check_int(char *str, char c)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != c)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_hexa(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (str[i] != '\0')
	{
		if (!ft_ishexa(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_int_hex(char *str)
{
	int		j;
	char	*ptr;

	j = 0;
	ptr = ft_strchr(str, ',');
	ptr++;
	if (!check_int(str, ',') && !check_hexa(ptr))
		return (1);
	return (0);
}

/*
The function copy_z_data is used to copy the z data from the file.
*/

static int	copy_z_data(t_map **map, char **str, int i)
{
	int		j;
	char	**hex;

	j = 0;
	hex = NULL;
	printf("DEBUT TEST CC\n");
	while (str[j])
	{
		if (!check_int(str[j], '\0'))
		{
			map[i][j].z = ft_atoi(str[j]);
		}
		else if (!check_int_hex(str[j]))
		{
			hex = ft_split(str[j], ',');
			map[i][j].z = ft_atoi(hex[0]);
			map[i][j].color = ft_hexatoi(hex[1]);
			free_null_2d_array(hex);
		}
		else
		{
			perror("Error: unvalid map!\n");
			return (1);
		}
		j++;
	}
	printf("TEST CC\n");
	return (0);
}

/*
The function get_z_data() is used to get the z data from the file.
*/

void	get_z_data(t_map **map,t_size size, char *file)
{
	int		fd;
	int		line_num;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	line_num = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		free(line);
		if (copy_z_data(map, split, line_num))
		{
			free_null_2d_array(split);
		}
		else
		{
			free_null_2d_array(split);
			free_2d_array(map, size.row);
			close(fd);
			exit(1);
		}
		line_num++;
	}
}
