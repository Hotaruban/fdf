/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:24:38 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/14 03:13:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include "./includes/libft.h"

int	main(int ac, char **av)
{
	if (check_error_extension(av[1]))
	{
		ft_putstr("Error: invalid file extension\n");
		return (0);
	}
	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf <filename>\n");
		return (0);
	}
	open_mlx(/*map_calculate*/);
	return (0);
}
