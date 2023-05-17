/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:20:26 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/17 23:20:21 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
The free_2d_array function will free the memory of a double pointer.
*/

void	free_2d_array(t_map **ptr, int i)
{
	while (i)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}

/*
The free_null_2d_array function will free the memory of a double pointer.
*/

void	free_null_2d_array(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
