/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:24:38 by jhurpy            #+#    #+#             */
/*   Updated: 2023/05/11 18:15:28 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	/*if (ac != 2)
	{
		ft_putstr("Usage: <filename>./fdf\n");
		return (0);
	}
	if (check_error_extension(av[1]))
	{
		ft_putstr("Error: invalid file extension\n");
		return (0);
	}
	if (check_error_map(av[1]))
	{
		ft_putstr("Error: invalid map\n");
		return (0);
	}*/
	open_mlx(av[1]);
	return (0);
}
