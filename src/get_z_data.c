/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 01:11:27 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/29 03:56:57 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The check_int, check_hexa and check_int_hex are used to check the
validity of the z data.
*/

static int	check_int(char *str, char c)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (1);
	}
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
	char	*ptr;

	ptr = ft_strchr(str, ',');
	ptr++;
	if (!check_int(str, ',') && !check_hexa(ptr))
	{
		if (ft_strlen(ptr) < 4 || ft_strlen(ptr) > 8)
			return (1);
		return (0);
	}
	return (1);
}

/*
The copy_z_data is used to copy the z data from the file.
*/

static void	copy_z_data(t_data sdata, char **str, int i, int fd)
{
	int		j;
	char	**hex;

	j = 0;
	hex = NULL;
	while (str[j])
	{
		if (!check_int(str[j], '\0'))
			sdata.map[i][j].z = (float)ft_atoi(str[j]);
		else if (!check_int_hex(str[j]))
		{
			hex = ft_split(str[j], ',');
			sdata.map[i][j].z = (float)ft_atoi(hex[0]);
			sdata.map[i][j].color = ft_hexatoi(hex[1]);
			free_null_2d_array(hex);
		}
		else
		{
			free_null_2d_array(str);
			free_2d_array(sdata.map, sdata.size.row);
			exit_close_fd(fd, "Error: Invalid map!");
		}
		j++;
	}
}

/*
The get_z_data is used to get the z data from the file.
*/

void	get_z_data(t_data sdata, char *file)
{
	int		fd;
	int		line_num;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	line_num = 0;
	line = get_next_line(fd);
	line[ft_strlen(line) - 1] = '\0';
	while (line != NULL)
	{
		split = ft_split(line, ' ');
		free(line);
		copy_z_data(sdata, split, line_num, fd);
		free_null_2d_array(split);
		line = get_next_line(fd);
		if (line != NULL)
			line[ft_strlen(line) - 1] = '\0';
		line_num++;
	}
	close(fd);
}
