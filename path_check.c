/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 04:44:25 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/05 18:24:29 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(char *line)
{
	int	cc;
	int	i;

	i = 0;
	cc = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			cc++;
		i++;
	}
	return (cc);
}

int	path_to_c(char **map_2d, int a, int b)
{
	int	i;
	int	j;
	int	c;

	i = a;
	j = b;
	c = 0;
	if (i > dimension(map_2d).y || j > dimension(map_2d).x)
		return (c);
	if (map_2d[i][j] == '1' || map_2d[i][j] == 'k' || map_2d[i][j] == 'E')
		return (c);
	if (map_2d[i][j] == '0' || map_2d[i][j] == 'C' || map_2d[i][j] == 'P')
	{
		if (map_2d[i][j] == 'C')
			c++;
		map_2d[i][j] = 'k';
		c += path_to_c(map_2d, i - 1, j);
		c += path_to_c(map_2d, i, j + 1);
		c += path_to_c(map_2d, i + 1, j);
		c += path_to_c(map_2d, i, j - 1);
	}
	return (c);
}

int	path_to_e(char **map_2d, int a, int b)
{
	int	i;
	int	j;
	int	c;

	i = a;
	j = b;
	c = 0;
	if (i > dimension(map_2d).y || j > dimension(map_2d).x)
		return (c);
	if (map_2d[i][j] == '1' || map_2d[i][j] == 'a')
		return (c);
	if (map_2d[i][j] == '0' || map_2d[i][j] == 'C' || map_2d[i][j] == 'E'
		|| map_2d[i][j] == 'P')
	{
		if (map_2d[i][j] == 'E')
			c++;
		map_2d[i][j] = 'a';
		c += path_to_e(map_2d, i - 1, j);
		c += path_to_e(map_2d, i, j + 1);
		c += path_to_e(map_2d, a + 1, b);
		c += path_to_e(map_2d, a, b - 1);
	}
	return (c);
}

void	path_check(t_mlx all, int a, int b)
{
	int		collect;
	int		nb_collect;
	char	**map;
	int		valid_exit;

	map = ft_split(all.line, '\n');
	collect = path_to_c(map, a, b);
	nb_collect = count_collectible(all.line);
	ft_free(map);
	map = ft_split(all.line, '\n');
	valid_exit = path_to_e(map, a, b);
	ft_free(map);
	if (nb_collect != collect)
		retour_erreur("Incorrect path to collectible item !!");
	if (valid_exit != 1)
		retour_erreur("Incorrect path to the exit !!");
}
