/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:47:05 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/04 23:08:44 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_check(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			retour_erreur("Missing File !!");
		if (ft_strlen(argv[1]) == 4)
			retour_erreur("Machi File !!");
		i = ft_strlen(argv[1]);
		i--;
		if ((argv[1][i--] != 'r' || argv[1][i--] != 'e' || argv[1][i--] != 'b'
			|| argv[1][i--] != '.'))
			retour_erreur("Invalid File name !!");
	}
	else
		retour_erreur("Invalid number of arguments !!");
}

void	item_check(char *line)
{
	int	i;
	int	nb_players;
	int	nb_collects;
	int	nb_exits;

	nb_collects = 0;
	nb_exits = 0;
	nb_players = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			nb_exits++;
		else if (line[i] == 'P')
			nb_players++;
		else if (line[i] == 'C')
			nb_collects++;
		i++;
	}
	if (nb_players != 1)
		retour_erreur("it must be exactly 1 player !!");
	if (nb_exits != 1)
		retour_erreur("it must be exactly 1 exit !!");
	if (nb_collects == 0)
		retour_erreur("There is no collectable !!");
}

void	form_check(char **map_2d, char *line)
{
	int	i;
	int	len;

	len = ft_strlen(map_2d[0]);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			retour_erreur("Empty line inside !!");
		i++;
	}
	i = 0;
	while (map_2d[i])
	{
		if (ft_strlen(map_2d[i]) != len)
			retour_erreur("Invalid Wall !!");
		i++;
	}
}

void	wall_check(char *line)
{
	char	**map_2d;
	int		i;
	int		j;

	j = 0;
	map_2d = ft_split(line, '\n');
	while (map_2d[j] != NULL)
		j++;
	i = 0;
	while (map_2d[0][i])
	{
		if (map_2d[0][i] != '1' || map_2d[j - 1][i] != '1')
			retour_erreur("Invalid Wall !!");
		i++;
	}
	i = 1;
	while (map_2d[i] != NULL)
	{
		if (map_2d[i][0] != '1' || map_2d[i][ft_strlen(map_2d[0]) - 1] != '1')
			retour_erreur("Invalid Wall !!");
		i++;
	}
	ft_free(map_2d);
}
