/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:35:56 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/12 13:33:46 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// void	ft_copy_map(t_game *game)
// {
	
// 	if (game->flag == 0)
// 		game->map.lluf[y][x] = game->map.full[y][x];
// 	if (game->flag == 1)
// 		game->map.full[y][x] = game->map.lluf[y][x];
// }

void	ft_render_coins(t_game *game, int y, int x, char prm)
{
	// printf("\n +++ RENDER COINS +++ \n");
	if (prm == COIN_1)
		ft_render_sprite (game, game->coins1, y, x);
	else if (prm == COIN_2)
		ft_render_sprite (game, game->coins2, y, x);
	else if (prm == COIN_3)
		ft_render_sprite (game, game->coins3, y, x);
	else if (prm == COIN_4)
		ft_render_sprite (game, game->coins4, y, x);
}

void	ft_convert_enemies(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 4;
	printf("\nCONVERT ENEMIES\n");
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == ENEMIES)
			{
				i++;
				if (i == 7)
					i = 5;
				ft_convert_maps(game, y, x, i);
			}
			printf("%c", game->map.lluf[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	ft_animation(void *param)
{
	t_game		*game;
	static int	count;

	game = param;
	++count;
	if (count > ANIMATION_SPEED)
	{
		printf("\n ANIMATION \n");
		if (game->flag == 0)
		{
			printf("\n flag = %d \n", game->flag);
			ft_enemies_move_0(game);
			game->flag = 1;
			
		}
		else if (game->flag == 1)
		{
			printf("\n flag = %d \n", game->flag);
			ft_enemies_move_1(game);
			game->flag = 0;
		}
		count = 1;
	}
}

void	ft_render_enemies(t_game *game, int enemy_type, int y, int x)
{
	int			t;
	static int	i;
	
	t = enemy_type;
	i++;
	// printf(" +++ RENDER ENEMIES +++ ");
	// printf("i = %d /// enemy_t = %d /// x = %d /// y = %d /// xx = %d /// yy = %d /// bool = %u\n   ===   \n", i, t, game->map.enemy[i].x, game->map.enemy[i].y, game->map.enemy[i].xx, game->map.enemy[i].yy, game->map.enemy[i].bool);
	if (game->map.enemy[i].bool == false)
	{
		printf("\nt'es sérieux, là?\n");
		if (t == 1)
			ft_render_sprite (game, game->enemy1_1, y, x);
		else if (t == 2)
			ft_render_sprite (game, game->enemy2_1, y, x);
	}
	else if (game->map.enemy[i].bool == true)
	{
		if (game->flag == 0 && t == 1)
			ft_render_sprite (game, game->enemy1_1, y, x);
		else if (game->flag == 0 && t == 2)
			ft_render_sprite (game, game->enemy2_1, y, x);
		else if (game->flag == 1 && t == 1)
			ft_render_sprite (game, game->enemy1_2, y, x);
		else if (game->flag == 1 && t == 2)
			ft_render_sprite (game, game->enemy2_2, y, x);
	}
	if (i == game->map.enemies)
		i = 0;
}
	



	
// 	if (game->flag == 0 && t == 1 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_1.xpm_ptr, (column + 1) * game->enemy1_1.x, line * game->enemy1_1.y);
// 	else if (game->flag == 0 && t == 2 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_1.xpm_ptr, (column + 1) * game->enemy2_1.x, line * game->enemy2_1.y);
// 	else if (game->flag == 1 && t == 1 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_2.xpm_ptr, column * game->enemy1_2.x, line * game->enemy1_2.y);
// 	else if (game->flag == 1 && t == 2 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_2.xpm_ptr, column * game->enemy2_2.x, line * game->enemy2_2.y);
// 	else if (game->flag == 0 && t == 1)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_1.xpm_ptr, column * game->enemy1_1.x, line * game->enemy1_1.y);
// 	else if (game->flag == 0 && t == 2)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_1.xpm_ptr, column * game->enemy2_1.x, line * game->enemy2_1.y);
// 	else if (game->flag == 1 && t == 1)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_2.xpm_ptr, column * game->enemy1_2.x, line * game->enemy1_2.y);
// 	else if (game->flag == 1 && t == 2)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_2.xpm_ptr, column * game->enemy2_2.x, line * game->enemy2_2.y);
// }

// void	ft_animation(void *param)
// {
// 	t_game		*game;
// 	static int	count;
// 	static int	flag;
// 	void		*mlx;

// 	mlx = game->mlx_ptr;
// 	game = param;
// 	++count;
// 	if (count > ANIMATION_SPEED)
// 	{
// 		if (flag == 0)
// 		{
// 			game->xpm.enemy1_1_xpm = "assets/solal/enemy1_2.xpm";
// 			flag = animate_enemies(game, flag, game->xpm.enemy1_1_xpm);
// 		}
// 		else if (flag == 1)
// 		{
// 			game->xpm.enemy1_1_xpm = "assets/solal/enemy1_2.xpm";
// 			flag = animate_enemies(game, flag, game->xpm.enemy1_1_xpm);
// 		}
// 		count = 1;
// 	}
// }

// int	animate_enemies(t_game *game, int flag, char *path)
// {
// 	mlx_delete_image(game->mlx, game->img.strong[i].image);
// 	place_png_to_img(game, &game->img.strong[i].image, path);
// 	mlx_image_to_window(game->mlx, game->img.strong[i].image, \
// 		strong_x * IMG_WIDTH, strong_y * IMG_HEIGHT);
// 	i++;
// 	if (i == game->map.strongs && flag == 0)
// 		return (1);
// 	if ((i == game->map.strongs && flag == 1) || flag == 0)
// 		return (0);
// 	return (1);
// }
