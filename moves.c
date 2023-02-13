/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:52:28 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/04 10:20:35 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_mlx *all, int x, int y, int *c)
{
	char	temp;

	if (all->map_2d[x][y] == 'E' && all->c_count == 0)
	{
		ft_printf("%d\nWinner Winner Chicken Dinner !!\n", ++*c);
		exit(0);
	}
	if (all->map_2d[x][y] != '1' && all->map_2d[x][y] != 'E')
	{
		if (all->map_2d[x][y] == 'C')
		{
			all->c_count--;
		}
		ft_printf("%d\n", ++*c);
		temp = all->map_2d[x + 1][y];
		all->map_2d[x + 1][y] = all->map_2d[x][y];
		all->map_2d[x][y] = temp;
		all->map_2d[x + 1][y] = '0';
		ground_display(all, x + 1, y);
		items_display(all, "./sources/player2.xpm", x, y);
	}
	return (0);
}

int	move_right(t_mlx *all, int i, int j, int *c)
{
	char	temp;

	if (all->map_2d[i][j] == 'E' && all->c_count == 0)
	{
		ft_printf("%d\nWinner Winner Chicken Dinner !!\n", ++*c);
		exit(0);
	}
	if (all->map_2d[i][j] != '1' && all->map_2d[i][j] != 'E')
	{
		if (all->map_2d[i][j] == 'C')
			all->c_count--;
		ft_printf("%d\n", ++*c);
		temp = all->map_2d[i][j - 1];
		all->map_2d[i][j - 1] = all->map_2d[i][j];
		all->map_2d[i][j] = temp;
		all->map_2d[i][j - 1] = '0';
		ground_display(all, i, j - 1);
		items_display(all, "./sources/player2.xpm", i, j);
	}
	return (0);
}

int	move_down(t_mlx *all, int i, int j, int *c)
{
	char	temp;

	if (all->map_2d[i][j] == 'E' && all->c_count == 0)
	{
		ft_printf("%d\nWinner Winner Chicken Dinner !!\n", ++*c);
		exit(0);
	}
	if (all->map_2d[i][j] != '1' && all->map_2d[i][j] != 'E')
	{
		if (all->map_2d[i][j] == 'C')
			all->c_count--;
		ft_printf("%d\n", ++*c);
		temp = all->map_2d[i - 1][j];
		all->map_2d[i - 1][j] = all->map_2d[i][j];
		all->map_2d[i][j] = temp;
		all->map_2d[i - 1][j] = '0';
		ground_display(all, i - 1, j);
		items_display(all, "./sources/player2.xpm", i, j);
	}
	return (0);
}

int	move_left(t_mlx *all, int i, int j, int *c)
{
	char	temp;

	if (all->map_2d[i][j] == 'E' && all->c_count == 0)
	{
		ft_printf("%d\nWinner Winner Chicken Dinner !!\n", ++*c);
		exit(0);
	}
	if (all->map_2d[i][j] != '1' && all->map_2d[i][j] != 'E')
	{
		if (all->map_2d[i][j] == 'C')
			all->c_count--;
		ft_printf("%d\n", ++*c);
		temp = all->map_2d[i][j + 1];
		all->map_2d[i][j + 1] = all->map_2d[i][j];
		all->map_2d[i][j] = temp;
		all->map_2d[i][j + 1] = '0';
		ground_display(all, i, j + 1);
		items_display(all, "./sources/player2.xpm", i, j);
	}
	return (0);
}
