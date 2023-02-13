/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:49:58 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/05 18:22:58 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int key, t_mlx *all)
{
	static int	c;
	int			i;
	int			j;

	i = player_position(all->map_2d).x;
	j = player_position(all->map_2d).y;
	if (key == 53)
	{
		ft_printf("you closed the game using ESC !!");
		mlx_destroy_window(all->init_ptr, all->window_ptr);
		exit(0);
	}
	if (key == 126 || key == 13)
		c += move_up(all, i - 1, j, &c);
	else if (key == 124 || key == 2)
		c += move_right(all, i, j + 1, &c);
	else if (key == 125 || key == 1)
		c += move_down(all, i + 1, j, &c);
	else if (key == 123 || key == 0)
		c += move_left(all, i, j - 1, &c);
	return (c);
}

int	mouse_press(t_mlx *all)
{
	ft_printf("You closed the game !!");
	mlx_destroy_window(all->init_ptr, all->window_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlx	all;
	t_dim	dim;

	if (argc == 2)
	{
		all.argv = argv[1];
		all.line = map_1d(all.argv);
		all.map_2d = ft_split(all.line, '\n');
		all.c_count = count_collectible(all.line);
		dim = dimension(all.map_2d);
		check_arg_form_path(argc, argv, all);
		all.init_ptr = mlx_init();
		all.argv = argv[1];
		all.window_ptr = mlx_new_window(all.init_ptr, (dim.x + 1) * 60, (dim.y
					+ 1) * 60, "GAME dial walo");
		map_display(&all);
		mlx_hook(all.window_ptr, 2, 0, moves, &all);
		mlx_hook(all.window_ptr, 17, 0, mouse_press, &all);
		mlx_loop(all.init_ptr);
	}
	else
		retour_erreur("invalid number of arguments !!");
}
