/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:28:27 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/12 16:11:56 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libraries/mlx/mlx.h"
# include "../libraries/Libft/libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'
# define COIN_1 		 	'9'
# define COIN_2 		 	'8'
# define COIN_3 		 	'7'
# define COIN_4 		 	'6'
# define ALL_4_COINS		"6789"
# define ENEMIES			'X'
# define ALL_ENEMIES		"YZ"
# define ENEMY_1			'Y'
# define ENEMY_2			'Z'

# define ANIMATION_SPEED	10000

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define KEY_LEFT  			123
# define KEY_RIGHT 			124
# define KEY_DOWN  			125
# define KEY_UP  			126

# define KEY_Q				12
# define KEY_ESC			53

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_position_bis
{
	int	x;
	int	y;
	int	xx;
	int	yy;
	t_bool bool;
}	t_positon_bis;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char			**full;
	char			**lluf;
	int				rows;
	int				columns;
	int				coins;
	int				exit;
	int				enemies;
	int				players;
	t_positon		player;
	t_positon_bis	enemy[100];
}	t_map;

typedef struct s_xpm
{
	char	*wall_xpm;
	char	*floor_xpm;
	char	*coins1_xpm;
	char	*coins2_xpm;
	char	*coins3_xpm;
	char	*coins4_xpm;
	char	*front_xpm;
	char	*right_xpm;
	char	*left_xpm;
	char	*back_xpm;
	char	*enemy1_1_xpm;
	char	*enemy1_2_xpm;
	char	*enemy2_1_xpm;
	char	*enemy2_2_xpm;
	char	*exit_open_xpm;
	char	*exit_closed_xpm;
}	t_xpm;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*buf;
	int			flag;
	int			movements;
	int			p_sprite;
	int			e_sprite;
	int			parallel_uni;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins1;
	t_image		coins2;
	t_image		coins3;
	t_image		coins4;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		p_front;
	t_image		p_left;
	t_image		p_right;
	t_image		p_back;
	t_image		enemy1_1;
	t_image		enemy2_1;
	t_image		enemy1_2;
	t_image		enemy2_2;
	t_xpm		xpm;
}	t_game;

void	ft_verif_args(int argc, char **argv, t_game *game);
void	ft_init_map_0(t_game *game, char *argv);
void	ft_init_map_1(t_game *game, char *argv);
char	*ft_sl_join(char **s1, const char *s2);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_init_vars(t_game *game);
void	ft_verif_map(t_game *game);
void	ft_verif_rows(t_game *game);
size_t	ft_strlen_line(const char *str);
void	ft_verif_columns(t_game *game);
void	ft_count_map_params(t_game *game);
void	ft_verify_map_params(t_game *game);
void	ft_convert_maps(t_game *game, int y, int x, int i);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
int		ft_render_game(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);
int		ft_key_hook(int keysym, t_game *game);
void	ft_p_move_0(t_game *game, int x, int y, int p_sprite);
void	ft_p_move_1(t_game *game, int x, int y, int p_sprite);
int		ft_victory(t_game *game);
int		ft_error_msg(char *message, t_game *game);
int		ft_killed(t_game *game);
int		ft_quit_game(t_game *game);
void	ft_free_all_game(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_game(t_game *game);
void	ft_sprite_path(t_game *game);
void	ft_parallel_universe(t_game *game);
void	ft_convert_coins(t_game *game);
void	ft_convert_enemies(t_game *game);
void	ft_check_space_to_move_enemies(t_game *game, int y, int x);
void	ft_render_coins(t_game *game, int y, int x, char prm);
void	ft_render_enemies(t_game *game, int t, int y, int x);
void	ft_animation(void *param);
void	ft_enemies_move_0(t_game *game);
void	ft_enemies_move_1(t_game *game);
void	ft_enemy_move_0(t_game *game, int t);
void	ft_enemy_move_1(t_game *game, int t);
// void	ft_copy_map(t_game *game);

#endif
