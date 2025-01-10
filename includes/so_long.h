/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:55:16 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/10 18:21:26 by mavellan         ###   ########.fr       */
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


//Error message
# define PARAMETERS_ERROR "ERROR\nYou must pass as parameter only the map\n"
# define FILE_EXTENSION_ERROR "ERROR\nYou must pass as parameter a .ber file\n"
# define FILE_MAP "ERROR\nError while validatig map.\n"
# define INCONSISTENT_MAP_WIDTH "ERROR\nInconsistent map width.\n"
# define INVALID_CHAR_MAP "ERROR\nInvalid character in map: %c\n"
# define MLX_INTI "ERROR\nMLX initializatio failed.\n"
// Estrucutra para el mapa
# define TILE_SIZE 32

typedef struct s_game {
	mlx_t		*mlx;
	mlx_image_t	*wall_img;
	mlx_image_t	*floor_img;
	char		**map;
	int			width;
	int			height;
}	t_game;

int		ft_error(int nbr_error);
int		check_file_extension(char *file_name);
void	free_map(char **map, int rows);
int		load_and_validate_map(const char *file_p, char ***map, int *w, int *h);
int		load_map_lines(int fd, char ***map, int *width, int *rows);
char	**resize_map(char **map, int capacity, int rows);
int		validate_line(const char *line, int expected_width);
void	render_title(t_game *game, int x, int y, char tile);
void	render_map(t_game *game);
void	cleanup(t_game *game, mlx_texture_t *wall, mlx_texture_t *floor);
int		read_line_from_file(int fd, char ***map, int *rows, int *capacity);


#endif