/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:48:56 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/04 23:07:52 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	retour_erreur(char *error)
{
	ft_printf("Error\n%s", error);
	exit(1);
}

void	retour_win(char *error)
{
	ft_printf("%s\n", error);
	exit(1);
}

char	*map_1d(char *argv)
{
	char	*line;
	char	*fullmap;
	int		fd;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		retour_erreur("Missing File !!");
	fullmap = ft_calloc(1, 1);
	line = get_next_line(fd);
	if (line == NULL)
		retour_erreur("No line !!");
	while (line != NULL)
	{
		temp = ft_strjoin(fullmap, line);
		free(fullmap);
		free(line);
		fullmap = temp;
		line = get_next_line(fd);
	}
	if (fullmap[0] == '\n')
		retour_erreur("Empty line !!");
	return (fullmap);
}

void	check_invalid_char(t_mlx all)
{
	int	i;

	i = 0;
	while (all.line[i])
	{
		if (all.line[i] != 'P' && all.line[i] != '1' && all.line[i] != 'E'
			&& all.line[i] != 'C' && all.line[i] != '0' && all.line[i] != '\n')
			retour_erreur("Invalid character !!");
		i++;
	}
}

void	check_arg_form_path(int argc, char **argv, t_mlx all)
{
	t_dim	pp;

	pp = player_position(all.map_2d);
	arg_check(argc, argv);
	form_check(all.map_2d, all.line);
	wall_check(all.line);
	item_check(all.line);
	check_invalid_char(all);
	path_check(all, pp.x, pp.y);
}
