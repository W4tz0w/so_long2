/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:29:59 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/12 23:00:24 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		ft_render_game(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);

int	ft_render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	printf("\n +++ RENDER GAME +++ \n");
	while (y < game->map.rows)
	{
		// printf("\n");
		x = 0;
		while (x < game->map.columns)
		{
			// printf("%c", game->map.full[y][x]);
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_identify_sprite(t_game *game, int y, int x)
{
	char	prm;

	if (game->flag == 0)
	{
		prm = game->map.lluf[y][x];
		printf("");
	}
	else
		prm = game->map.full[y][x];
	if (prm == WALL)
		ft_render_sprite (game, game->wall, y, x);
	else if (prm == FLOOR)
		ft_render_sprite (game, game->floor, y, x);
	else if (prm == COIN_1 || prm == COIN_2 || prm == COIN_3 || prm == COIN_4)
		ft_render_coins (game, y, x, prm);
	else if (prm == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite (game, game->open_exit, y, x);
		else
			ft_render_sprite (game, game->exit_closed, y, x);
	}
	else if (prm == ENEMY_1)
		ft_render_enemies(game, 1, y, x);
	else if (prm == ENEMY_2)
		ft_render_enemies(game, 2, y, x);
	else if (prm == PLAYER)
		ft_render_player (game, y, x);
}

void	ft_render_player(t_game *game, int y, int x)
{
	if (game->p_sprite == FRONT)
		ft_render_sprite (game, game->p_front, y, x);
	if (game->p_sprite == LEFT)
		ft_render_sprite (game, game->p_left, y, x);
	if (game->p_sprite == RIGHT)
		ft_render_sprite (game, game->p_right, y, x);
	if (game->p_sprite == BACK)
		ft_render_sprite (game, game->p_back, y, x);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

void	ft_print_movements(t_game *game)
{
	char			*movements;
	char			*str;
	static int		i;

	movements = ft_itoa(game->movements);
	str = ft_strjoin("Movements : ", movements);
	if (i == 1)
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 21, 999999999, str);
		i--;
	}
	else if (i == 0)
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 21, 0, str);
		i++;
	}
	free(movements);
	free(str);
}
