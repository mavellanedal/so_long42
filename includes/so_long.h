/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:03 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 18:11:36 by mavellan         ###   ########.fr       */
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

typedef struct s_dimensions
{
	int	cols;
	int	rows;
}	t_dimensions;

//map_checks2.c
char		**read_map(const char *path, int *rows);
int			process_lines(int fd, char **map);
int			check_file_extension(char *file_name);
int			is_initial_pos(char **map);
int			is_colectionables(char **map);

//map_checks3.c
int			count_lines(const char *path);
int			is_valid_chars(char **map);
int			is_exit(char **map);
int			is_rectangular(char **map);
int			is_closed(char **map, int rows);

//map_checks.c
int			map_checks(char **map, int rows, char *file_names);

//utils.c
void		free_map(char **map);

//ft_error.c
int			ft_error(int i);
int			ft_error2(int i);
int			check_error(char *path, int i);
int			check_error2(char *path, int i);

//renders.c
int			render_walls(mlx_t *mlx, char **map, int rows, int cols);
int			render_floor(mlx_t *mlx, char **map, int rows, int cols);
int			render_coin(mlx_t *mlx, char **map, int rows, int cols);
int			render_player(mlx_t *mlx, char **map, int rows, int cols);

//so_long.c
int			start_game(char **map, int rows, int cols);

//make_images.c
mlx_image_t	*create_image(mlx_t *mlx, char assets);

#endif
