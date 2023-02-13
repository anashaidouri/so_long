/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:56:53 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/04 22:56:51 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*init_ptr;
	void	*window_ptr;
	void	*image_ptr;
	char	*argv;
	char	*line;
	char	**map_2d;
	int		c_count;
}			t_mlx;

typedef struct s_dim
{
	int		x;
	int		y;
}			t_dim;

void		ft_free(char **str);
void		*str_free(char ***str, int j);
void		retour_erreur(char *error);
void		retour_win(char *error);
char		*map_1d(char *argv);
t_dim		dimension(char **map_2d);
void		arg_check(int argc, char **argv);
void		item_check(char *line);
void		form_check(char **map_2d, char *line);
void		wall_check(char *line);
t_dim		player_position(char **map_2d);
int			count_collectible(char *line);
int			path_to_c(char **map_2d, int a, int b);
int			path_to_e(char **map_2d, int a, int b);
void		path_check(t_mlx all, int a, int b);
void		check_arg_form_path(int argc, char **argv, t_mlx all);
void		ground_display(t_mlx *all, int a, int b);
void		wall_display(t_mlx *all, int a, int b);
void		ground_display(t_mlx *all, int a, int b);
void		items_display(t_mlx *all, char *source, int i, int j);
void		map_display(t_mlx *all);
int			move_up(t_mlx *all, int i, int j, int *c);
int			move_right(t_mlx *all, int i, int j, int *c);
int			move_down(t_mlx *all, int i, int j, int *c);
int			move_left(t_mlx *all, int i, int j, int *c);

#endif
