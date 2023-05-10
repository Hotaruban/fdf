/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_creat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 03:33:23 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/10 03:43:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include "./includes/libft.h"

void	realloc_2d_array(char ***ptr, size_t old_size, size_t new_size)
{
	char	**new_ptr;

	if (new_size == 0)
	{
		free(*ptr);
		*ptr = NULL;
		return ;
	}
	new_ptr = (char **)malloc(sizeof(char *) * (new_size + 1));
	if (new_ptr == NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return ;
	}
	if (*ptr != NULL)
	{
		ft_memcpy(new_ptr, *ptr, old_size * sizeof(char *));
		free(*ptr);
	}
	*ptr = new_ptr;
	(*ptr)[new_size] = NULL;
}
