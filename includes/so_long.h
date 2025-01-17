/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:03 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 11:28:12 by mavellan         ###   ########.fr       */
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

# define TILE_SIZE 60

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
# define WALL_TEXTURE_LOAD "ERROR\nCargando la textura del muro\n"
# define CREATE_WALL_IMG "ERROR\nCreando la imagen del muro\n"
# define DRAW_WALL "ERROR\nDibujando la imagen del muro\n"

//map_checks2.c
char	**read_map(const char *path, int *rows);
int		process_lines(int fd, char **map);
int		check_file_extension(char *file_name);
int		is_initial_pos(char **map);
int		is_colectionables(char **map);

//map_checks3.c
int		count_lines(const char *path);
int		is_valid_chars(char **map);
int		is_exit(char **map);
int		is_rectangular(char **map);
int		is_closed(char **map, int rows);

//map_checks.c
int		map_checks(char **map, int rows, char *file_names);

//utils.c
void	free_map(char **map);

//ft_error.c
int		ft_error(int i);
int		ft_error2(int i);

//renders.c
int		render_walls(mlx_t *mlx, char **map, int rows, int cols);

//so_long.c
int		start_game(char **map, int rows, int cols);
#endif
