/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:29:34 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/29 03:55:59 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The exit_error will exit the program and print the error message.
*/

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

/*
The exit_error_2d_arrays will free the memory and exit the program.
*/

void	exit_error_2d_arrays(t_map **ptr, int i, char *str)
{
	while (i)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	exit_error(str);
}

/*
The free_memory_close_fd function will free the memory and close the file.
*/

void	exit_free_close_fd(void *ptr, int fd, char *str)
{
	ft_putstr_fd(str, 2);
	free(ptr);
	close(fd);
	exit(1);
}

/*
The exit_close_fd function will close the file and exit the program.
*/

void	exit_close_fd(int fd, char *str)
{
	ft_putstr_fd(str, 2);
	close(fd);
	exit(1);
}
