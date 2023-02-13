/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:19:38 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/04 10:20:43 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ground_display(t_mlx *all, int a, int b)
{
	int	width;
	int	height;

	all->image_ptr = mlx_xpm_file_to_image(all->init_ptr,
			"./sources/ground2.xpm",
			&width,
			&height);
	if (!all->image_ptr)
		retour_erreur("Invalid xpm file !!");
	mlx_put_image_to_window(all->init_ptr, all->window_ptr, all->image_ptr, 60
		* b, 60 * a);
}

void	wall_display(t_mlx *all, int a, int b)
{
	int	width;
	int	height;

	all->image_ptr = mlx_xpm_file_to_image(all->init_ptr,
			"./sources/wall1.xpm",
			&width,
			&height);
	if (!all->image_ptr)
		retour_erreur("Invalid xpm file !!");
	mlx_put_image_to_window(all->init_ptr, all->window_ptr, all->image_ptr, 60
		* b, 60 * a);
}

void	items_display(t_mlx *all, char *source, int i, int j)
{
	int	width;
	int	height;

	ground_display(all, i, j);
	all->image_ptr = mlx_xpm_file_to_image(all->init_ptr,
			source,
			&width,
			&height);
	if (!all->image_ptr)
		retour_erreur("Invalid xpm file !!");
	mlx_put_image_to_window(all->init_ptr, all->window_ptr, all->image_ptr, 60
		* j, 60 * i);
}

void	map_display(t_mlx *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map_2d[i])
	{
		j = 0;
		while (all->map_2d[i][j])
		{
			if (all->map_2d[i][j] == '1')
				wall_display(all, i, j);
			else if (all->map_2d[i][j] == '0')
				ground_display(all, i, j);
			else if (all->map_2d[i][j] == 'P')
				items_display(all, "./sources/player2.xpm", i, j);
			else if (all->map_2d[i][j] == 'C')
				items_display(all, "./sources/collect2.xpm", i, j);
			else if (all->map_2d[i][j] == 'E')
				items_display(all, "./sources/exit.xpm", i, j);
			j++;
		}
		i++;
	}
}
