/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:31:09 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/31 12:24:39 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);

void	ft_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->p_sprite = FRONT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("La création du pointeur \
		'mlx_init' n'a pas marché!", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("La fenêtre s'est échouée. Comme un bateau.", game);
	}
}

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->coins1 = ft_new_sprite(mlx, COINS_1_XPM, game);
	game->coins2 = ft_new_sprite(mlx, COINS_2_XPM, game);
	game->coins3 = ft_new_sprite(mlx, COINS_3_XPM, game);
	game->coins4 = ft_new_sprite(mlx, COINS_4_XPM, game);
	game->p_front = ft_new_sprite(mlx, P_FRONT_XPM, game);
	game->p_left = ft_new_sprite(mlx, P_LEFT_XPM, game);
	game->p_right = ft_new_sprite(mlx, P_RIGHT_XPM, game);
	game->p_back = ft_new_sprite(mlx, P_BACK_XPM, game);
	game->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Le sprite n'existe pas. Le coca non plus.", game);
	return (sprite);
}
