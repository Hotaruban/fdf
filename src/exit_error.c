/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:29:34 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/17 23:23:19 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The function exit_error will exit the program and print the error message.
*/

void	exit_error(char *str)
{
	perror(str);
	exit(1);
}

/*
The function exit_error_2d_arrays will free the memory and exit the program.
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
	perror(str);
	free(ptr);
	close(fd);
	exit(1);
}
