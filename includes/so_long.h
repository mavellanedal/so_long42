/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:03 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/27 18:13:52 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define TILE_SIZE 32

//Error Messages
# define ARGV_MISSING "ERROR\nYou must provide the map as an argument.\n"
# define MLX_INIT "ERROR\nFailed to initialize MLX.\n"
# define READING_MAP "ERROR\nError reading the map.\n"
# define INVALID_CHARS "ERROR\nInvalid characters in the map.\n"
# define NOT_RECTANGUALR "ERROR\nThe map must be rectangular.\n"
# define NOT_CLOSED "ERROR\nThe map must be closed.\n"
# define NOT_EXIT "ERROR\nThe map must contain an exit.\n"
# define NOT_POSITION "ERROR\nThe map must contain a starting position.\n"
# define NOT_COLECTIONABLES "ERROR\nThe map must have at least \
	one collectible.\n"
# define FILE_EXTENSION "ERROR\nThe map file extension must be .ber.\n"
# define NO_ACCESIBLE "ERROR\nThe exit is not accessible.\n"
# define INIT_MLX "ERROR\nError initializing MLX.\n"
# define WALL_TEXTURE_LOAD "ERROR\nFailed to load the wall texture.\n"
# define CREATE_WALL_IMG "ERROR\nFailed to create the wall image.\n"
# define DRAW_WALL "ERROR\nFailed to draw the wall image.\n"
# define FLOOR_TEXTURE_LOAD "ERROR\nFailed to load the floor texture.\n"
# define CREATE_FLOOR_IMG "ERROR\nFailed to create the floor image.\n"
# define DRAW_FLOOR "ERROR\nFailed to draw the floor image.\n"
# define COIN_TEXTURE_LOAD "ERROR\nFailed to load the coin texture.\n"
# define CREATE_COIN_IMG "ERROR\nFailed to create the coin image.\n"
# define DRAW_COIN "ERROR\nFailed to draw the coin image.\n"
# define PLAYER_TEXTURE_LOAD "ERROR\nFailed to load the player texture.\n"
# define CREATE_PLAYER_IMG "ERROR\nFailed to create the player image.\n"
# define DRAW_PLAYER "ERROR\nFailed to draw the player image.\n"
# define EXIT_TEXTURE_LOAD "ERROR\nFailed to load the exit texture.\n"
# define CREATE_EXIT_IMG "ERROR\nFailed to create the exit image.\n"
# define DRAW_EXIT "ERROR\nFailed to draw the exit image.\n"
# define MENU_TEXTURE_LOAD "ERROR\nFailed to load the menu texture.\n"
# define CREATE_MENU_IMG "ERROR\nFailed to create the menu image.\n"
# define DRAW_MENU "ERROR\nFailed to draw the menu image.\n"
# define ENEMY_TEXTURE_LOAD "ERROR\nFailed to load the enemy texture.\n"
# define CREATE_ENEMY_IMG "ERROR\nFailed to create the enemy image.\n"
# define DRAW_ENEMY "ERROR\nFailed to draw the enemy image.\n"
# define STAR_TEXTURE_LOAD "ERROR\nFailed to load the star texture.\n"
# define CREATE_STAR_IMG "ERROR\nFailed to create the star image.\n"
# define DRAW_STAR "ERROR\nFailed to draw the star image.\n"

// Strucutres
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;
typedef struct s_enemy
{
	int	past_x;
	int	past_y;
	int	x;
	int	y;
}	t_enemy;

typedef struct s_stars
{
	int	x;
	int	y;
	int	visible;
}	t_star;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*wall_image;
	mlx_image_t	*floor_image;
	mlx_image_t	*coin_image;
	mlx_image_t	*animation_image1;
	mlx_image_t	*animation_image2;
	mlx_image_t	*animation_image3;
	mlx_image_t	*exit_image;
	mlx_image_t	*player_image;
	mlx_image_t	*menu_image;
	mlx_image_t	*enemy_image;
	t_pos		enemies[2];
	char		**map;
	char		**map_copy;
	int			rows;
	int			cols;
	int			player_x;
	int			player_y;
	int			moves;
	int			coins;
	int			total_coins;
	int			enemy_count;
	int			exit_x;
	int			exit_y;
}	t_game;

//map_checks2.c
char			**read_map(const char *path, t_game *game);
int				process_lines(int fd, t_game *game);
int				check_file_extension(char *file_name);
int				is_initial_pos(t_game *game);
int				is_colectionables(t_game *game);

//map_checks3.c
int				count_lines(const char *path);
int				is_valid_chars(t_game *game);
int				is_exit(t_game *game);
int				is_rectangular(t_game *game);
int				is_closed(t_game *game);

//map_checks4.c
int				find_exit_y(t_game *game);
int				find_exit_x(t_game *game);

//map_checks.c
int				flood_fill(t_game *game, int x, int y);
int				find_player_position(t_game *game);
char			**copy_map(char **map, int rows);
int				is_accesible(t_game *game);
int				map_checks(t_game *game, char *file_name);

//utils.c
void			free_map(t_game *game);
void			free_map_copy(t_game *game);
int				cont_coins(t_game *game);
void			update_enemy_instances(t_game *game);

//ft_error.c
int				ft_error(int i);
int				ft_error2(int i);
int				ft_error3(int i);
int				check_error(char asset, int i);
int				check_error2(char asset, int i);

//renders.c
int				render_walls(t_game *game);
int				render_floor(t_game *game);
int				render_coin(t_game *game);
int				render_coin2(t_game *game);
int				render_coin3(t_game *game);
int				render_player(t_game *game);
int				render_exit(t_game *game);

//renders2.c
int				render_animation1(t_game *game);
int				render_animation2(t_game *game);
int				render_animation3(t_game *game);

//so_long.c
int				start_game(t_game *game);
void			init_game_struct(t_game *game);

//make_images.c
mlx_image_t		*create_image(t_game *game, char asset);
char			*check_asset(char asset);

//player_movmets.c
void			check_enemies(t_game *game, int px, int py);
void			check_exit(t_game *game, int px, int py);
void			check_coins(t_game *game, int px, int py);
void			move_player(t_game *game, int dx, int dy);
void			handle_player_move(mlx_key_data_t keydata, void *param);

//display_game_info.c
int				render_menu(t_game *game);
void			update_game_info(t_game *game);
void			set_ppsitions(t_game *game, int new_x, int new_y);

//enemy.c
void			move_enemy_instances(t_game *game, int instance_index);
int				render_enemies(t_game *game);
void			place_enemies(t_game *game);
void			find_empty_positions(t_game *game, t_pos *positions);
int				count_empty_positions(t_game *game);

//animations.c
void			blink_player(void *param);
void			stop_animation(t_game *game);
void			animation(t_game *game);
void			hook_loop(void *param);
int				check_if_animation(t_game *game);

#endif
