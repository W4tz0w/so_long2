/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:28:36 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/12 12:44:31 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char	**argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_verif_args(argc, argv, game);
	ft_init_map_0(game, argv[1]);
	ft_init_map_1(game, argv[1]);
	ft_init_vars(game);
	ft_verif_map(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	// printf("HOW MANY TIMES\n");
	// ft_render_game(game);
	mlx_loop_hook(game->mlx_ptr, (int (*)())ft_animation, game);
	mlx_hook(game->win_ptr, 2, 0, ft_key_hook, game);
	mlx_hook(game->win_ptr, 17, 0, ft_quit_game, game);
	mlx_hook(game->win_ptr, 12, 0, ft_render_game, game);
	// system("leaks -atExit -- ./so_long_bonus");
	mlx_loop(game->mlx_ptr);
	printf("\n JUSTE POUR TEST \n");
	ft_free_all_game(game);
}

/* Add 	system("leaks -atExit -- ./so_long_bonus"); 
				on macOS too check for leaks */
/* Or just 	system("leaks ./so_long") on Linux */
