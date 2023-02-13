/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:49:37 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/04 10:20:49 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_dim	dimension(char **map_2d)
{
	int		i;
	int		width;
	int		height;
	t_dim	dim;

	width = ft_strlen(map_2d[0]) - 1;
	i = 0;
	while (map_2d[i] != NULL)
		i++;
	i--;
	height = i;
	dim.x = width;
	dim.y = height;
	return (dim);
}

t_dim	player_position(char **map_2d)
{
	t_dim	player_pos;
	int		i;
	int		j;

	i = 0;
	player_pos.x = 0;
	player_pos.y = 0;
	while (map_2d[i] != NULL)
	{
		j = 0;
		while (map_2d[i][j] != '\0')
		{
			if (map_2d[i][j] == 'P')
			{
				player_pos.x = i;
				player_pos.y = j;
				return (player_pos);
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}
