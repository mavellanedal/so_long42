/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:03 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/04 10:25:37 by mavellan         ###   ########.fr       */
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
# include <time.h>

# define TILE_SIZE 32

//Error Messages
# define ARGV_MISSING "ERROR\nYou must provide the map as an argument.\n"
# define MLX_INIT "ERROR\nFailed to initialize MLX.\n"
# define READING_MAP "ERROR\nError reading the map.\n"
# define INVALID_CHARS "ERROR\nInvalid characters in the map.\n"
# define NOT_RECTANGUALR "ERROR\nThe map must be rectangular.\n"
# define NOT_CLOSED "ERROR\nThe map must be closed.\n"
# define NO_CORRECT_CONTENTS "ERROR\nThe map have error contents.\n"
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
# define FILE_EMPTY "ERROR\nThe file is empty.\n"

// Strucutres
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_point
{
	int	row;
	int	col;
	int	max_rows;
	int	max_cols;
	int	check;
}	t_point;

typedef struct s_textures
{
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*coin_texture;
	mlx_texture_t	*animation1_texture;
	mlx_texture_t	*animation2_texture;
	mlx_texture_t	*animation3_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*menu_texture;
	mlx_texture_t	*enemy_texture;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*wall_image;
	mlx_image_t	*floor_image;
	mlx_image_t	*coin_image;
	mlx_image_t	*animation1_image;
	mlx_image_t	*animation2_image;
	mlx_image_t	*animation3_image;
	mlx_image_t	*player_image;
	mlx_image_t	*exit_image;
	mlx_image_t	*menu_image;
	mlx_image_t	*enemy_image;
}	t_images;

typedef struct s_game
{
	struct s_textures	*textures;
	struct s_images		*images;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	t_pos				animation_pos;
	t_pos				enemies;
	t_pos				aniamtion;
	int					player_x;
	int					player_y;
	int					moves;
	int					coins;
	int					total_coins;
	int					enemy_count;
	int					exit_x;
	int					exit_y;
}	t_game;

//bonus/animations.c
void			animation(t_game *game);
void			hook_loop(void *param);

//bonus/display_game_info.c
void			clear_counter(t_game *game, mlx_image_t **counter);
mlx_image_t		*create_counter_image(t_game *game);
void			ft_write_counter(t_game *game);

//parsing/parser.c
char			*ft_read_trimmed_line(int fd);
int				handle_overflow(char *trim, char **map, int fd, int *rows);
int				read_map(int fd, char **map, int *rows, int *cols);
char			**make_map(char *path, char **map, int *rows, int *cols);
char			**map_checks(char *path, int *rows, int *cols);

//parsing/parsing1.c
int				ft_check_row_wall(char *row, int len);
int				ft_check_if_close(char **map, int rows, int cols);
int				is_rectangular(char **map, int rows);
int				ft_empty_checker(char **map, int rows);
int				ft_checker(char **map, int rows, int cols);

//parsing/parsing2.c
void			ft_c_checker(char **map, int *c);
void			ft_e_checker(char **map, int *e);
void			ft_p_checker(char **map, int *p);
int				ft_check_chars(char **map);

//parsing/parsing3.c
t_point			*ft_create_point(int rows, int cols);
int				ft_cleanup(t_point *char_pos, char **flood_map, int ret);
int				ft_ent_count(char **map);
int				ft_valid_chars(char c);
int				ft_check_entities(char **map);

//parsing/parsing4.c
char			**ft_copy_map(char **map, int rows);
void			ft_locate_p(char **map, t_point *char_pos);
int				ft_is_target(char c);
void			ft_flood_fill(char **flood_m, t_point *char_pos, \
	int row, int col);
int				ft_check_path(char **map, int rows, int cols);

//game_inits/game_inits.c
char			**ft_load_map(char *path);
void			ft_mesure_map(t_game *game, char **map);
int				ft_init_game(t_game *game);

//game_inits/game_ender.c
void			ft_clean_images(t_game *game);
void			ft_cleanup_game(t_game *game);
void			ft_game_over(t_game *game);

//game_inits/images_renders.c
void			ft_create_textures(t_game *game);
void			ft_create_imgs(t_game *game);
void			ft_delete_textures(t_game *game);

//coins.c
int				cont_coins(t_game *game);
void			ft_delete_coin(t_game *game);
void			ft_collector(t_game *game);

//enemy.c
char			ft_detect_move(t_game *game);
void			move_enemy(t_game *game);
void			ft_enemy_detection(t_game *game);

//ft_error.c
int				ft_error(int i);
int				ft_error2(int i);
int				ft_error3(int i);
int				check_error(char asset, int i);
int				check_error2(char asset, int i);

//player_movmets.c
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			handle_player_move(mlx_key_data_t keydata, void *param);

//renders.c
void			ft_render_map(t_game *game, t_images *img);
void			ft_render_floor(t_game *game, t_images *image);

#endif
