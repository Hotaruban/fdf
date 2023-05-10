/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:20:26 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/10 03:12:25 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The free_2d_array function will free the memory of a double pointer.
*/

void	free_2d_array(void **ptr, int i)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
