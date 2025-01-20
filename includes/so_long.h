/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:03 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/20 16:03:15 by mavellan         ###   ########.fr       */
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

//Mensajes de error
# define ARGV_MISSING "ERROR\nDebes introducir el mapa como argumento.\n"
# define MLX_INIT "ERROR\nAl intentar inicializar MLX.\n"
# define READING_MAP "ERROR\nLeyendo el mapa.\n"
# define INVALID_CHARS "ERROR\nCaracteres invalidos en el mapa.\n"
# define NOT_RECTANGUALR "ERROR\nEl mapa debe ser rectangular.\n"
# define NOT_CLOSED "ERROR\nEl mapa debe estar cerrado.\n"
# define NOT_EXIT "ERROR\nEl mapa debe contener una salida\n"
# define NOT_POSITION "ERROR\nEl mapa debe contener una posicion de salida\n"
# define NOT_COLECTIONABLES "ERROR\nEl mapa debe tener un colceccionable\n"
# define FILE_EXTENSION "ERROR\nLa extension del mapa debe ser .ber\n"
# define NO_ACCESIBLE "ERROR\nLa salida no es accesible.\n"
# define INIT_MLX "ERROR\nInicalizando MLX.\n"
# define WALL_TEXTURE_LOAD "ERROR\nCargando la textura del muro.\n"
# define CREATE_WALL_IMG "ERROR\nCreando la imagen del muro.\n"
# define DRAW_WALL "ERROR\nDibujando la imagen del muro.\n"
# define FLOOR_TEXTURE_LOAD "ERROR\nCargando la textura del suelo.\n"
# define CREATE_FLOOR_IMG "ERROR\nCreando la imagen del suelo.\n"
# define DRAW_FLOOR "ERROR\nDibujando la imagen del suelo.\n"
# define COIN_TEXTURE_LOAD "ERROR\nCargando la textura de la moneda.\n"
# define CREATE_COIN_IMG "ERROR\nCreando la imagen de la moneda.\n"
# define DRAW_COIN "ERROR\nDibujando la imagen de la moneda.\n"
# define PLAYER_TEXTURE_LOAD "ERROR\nCargando la textura del jugador.\n"
# define CREATE_PLAYER_IMG "ERROR\nCreando la imagen del jugador.\n"
# define DRAW_PLAYER "ERROR\nDibujando la imagen del jugador.\n"
# define EXIT_TEXTURE_LOAD "ERROR\nCargando la textura de la salida.\n"
# define CREATE_EXIT_IMG "ERROR\nCreando la imagen de la salida.\n"
# define DRAW_EXIT "ERROR\nDibujando la imagen de la salida.\n"

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*wall_image;
	mlx_image_t	*floor_image;
	mlx_image_t	*coin_image;
	mlx_image_t	*exit_image;
	mlx_image_t	*player_image;
	char		**map;
	char		**map_copy;
	int			rows;
	int			cols;
	int			player_x;
	int			player_y;
}	t_game;

//map_checks2.c
char		**read_map(const char *path, t_game *game);
int			process_lines(int fd, t_game *game);
int			check_file_extension(char *file_name);
int			is_initial_pos(t_game *game);
int			is_colectionables(t_game *game);

//map_checks3.c
int			count_lines(const char *path);
int			is_valid_chars(t_game *game);
int			is_exit(t_game *game);
int			is_rectangular(t_game *game);
int			is_closed(t_game *game);

//map_checks.c
int			flood_fill(t_game *game, int x, int y);
int			find_player_position(t_game *game);
char		**copy_map(char **map, int rows);
int			is_accesible(t_game *game);
int			map_checks(t_game *game, char *file_name);

//utils.c
void		free_map(t_game *game);
void		free_map_copy(t_game *game);

//ft_error.c
int			ft_error(int i);
int			ft_error2(int i);
int			check_error(char asset, int i);
int			check_error2(char asset, int i);

//renders.c
int			render_walls(t_game *game);
int			render_floor(t_game *game);
int			render_coin(t_game *game);
int			render_player(t_game *game);
int			render_exit(t_game *game);

//so_long.c
int			start_game(t_game *game);

//make_images.c
mlx_image_t	*create_image(t_game *game, char asset);
char		*check_asset(char asset);

#endif
