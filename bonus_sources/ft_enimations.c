/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enimations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:54:19 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/11 23:52:33 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_space_to_move_enemies(t_game *game, int y, int x)
{
	static int	i;

	i++;
	game->map.enemy[i].y = y;
	game->map.enemy[i].x = x;
	game->map.enemy[i].xx = x;
	game->map.enemy[i].yy = y;
	game->map.enemy[i].bool = true;
	if (game->map.full[y][x + 1] == FLOOR)
		game->map.enemy[i].xx += 1;
	else if (game->map.full[y + 1][x] == FLOOR)
		game->map.enemy[i].yy += 1;
	else if (game->map.full[y][x - 1] == FLOOR)
		game->map.enemy[i].xx -= 1;
	else if (game->map.full[y - 1][x] == FLOOR)
		game->map.enemy[i].yy -= 1;
	else
		game->map.enemy[i].bool = false;
	printf("i = %d /// x = %d /// y = %d /// xx = %d /// yy = %d /// bool = %u\n   ===   \n", i, game->map.enemy[i].x, game->map.enemy[i].y, game->map.enemy[i].xx, game->map.enemy[i].yy, game->map.enemy[i].bool);
}

void	ft_enemies_move_0(t_game *game)
{
	int			x;
	int			y;
	
	y = 0;
	printf("\n+++ ENEMIES MOVE 000 +++\n");
	while (y < game->map.rows)
	{
		x = 0;
		// printf("\n");
		while (x < game->map.columns)
		{
			if (game->map.lluf[y][x] == ENEMY_2)
			{
				printf("{ flag = %d  =0=  ENEMY_2 }", game->flag);
				ft_enemy_move_0(game, 2);
			}
			else if (game->map.lluf[y][x] == ENEMY_1)
			{
				printf("{ flag = %d  ===  ENEMY_1 }", game->flag);
				ft_enemy_move_0(game, 1);
			}
			// printf("%c", game->map.full[y][x]);
			x++;
		}
		y++;
	}
	// printf("\n        ==== === == = == === ==== \n");
	ft_render_game(game);
}

void	ft_enemies_move_1(t_game *game)
{
	int			x;
	int			y;
	
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == ENEMY_2)
				ft_enemy_move_1(game, 2);
			else if (game->map.full[y][x] == ENEMY_1)
				ft_enemy_move_1(game, 1);
			x++;
		}
		y++;
	}
	ft_render_game(game);
}

void	ft_enemy_move_0(t_game *game, int t)
{
	static int	i;
	int			y;
	int			x;
	int			xx;
	int			yy;

	i++;
	y = game->map.enemy[i].y;
	x = game->map.enemy[i].x;
	xx = game->map.enemy[i].xx;
	yy = game->map.enemy[i].yy;
	if (t == 1)
	{
		if (game->map.full[yy][xx] == PLAYER)
			ft_killed(game);
		game->map.lluf[y][x] = FLOOR;
		game->map.lluf[yy][xx] = ENEMY_1;
	}
	else if (t == 2)
	{
		if (game->map.full[y][x] == PLAYER)
			ft_killed(game);
		game->map.lluf[yy][xx] = ENEMY_2;
		game->map.lluf[y][x] = FLOOR;
	}
	if (i == game->map.enemies)
		i = 0;
}

void	ft_enemy_move_1(t_game *game, int t)
{
	static int	i;
	int			y;
	int			x;
	int			xx;
	int			yy;

	i++;
	printf("\n +++ ENEMYyYyY_MOVE +++    i = %d\n", i);
	y = game->map.enemy[i].y;
	x = game->map.enemy[i].x;
	xx = game->map.enemy[i].xx;
	yy = game->map.enemy[i].yy;
	if (t == 1)
	{
		if (game->map.lluf[y][x] == PLAYER)
			ft_killed(game);
		game->map.full[yy][xx] = FLOOR;
		game->map.full[y][x] = ENEMY_1;
	}
	else if (t == 2)
	{
		if (game->map.lluf[yy][xx] == PLAYER)
			ft_killed(game);
		game->map.full[yy][xx] = FLOOR;
		game->map.full[y][x] = ENEMY_2;
	}
	if (i == game->map.enemies)
		i = 0;
}
