/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:36:45 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/12 22:41:50 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int store_line_in_map(char ***map, int *rows, int *capacity, char *line)
{
    if (*rows >= *capacity)
    {
        *map = resize_map(*map, *capacity, *rows);
        if (!*map)
        {
            free(line);
            return (-1);
        }
        *capacity *= 2;
    }
    (*map)[*rows] = line;
    (*rows)++;
    return (0);
}

int read_line_from_file(int fd, char ***map, int *rows, int *capacity) {
    char *line = get_next_line(fd);
    if (!line) return (0);  // Fin de archivo

    // Validamos la línea antes de continuar
    int line_width = validate_line(line, -1);  // Usamos -1 porque no necesitamos que nos pase el width aquí
    if (line_width == 0) {
        free(line);
        return (-1);  // Error de validación
    }

    // Asignamos el ancho de la línea si es necesario
    if (*capacity == -1) {
        *capacity = line_width;
    }

    // Almacenamos la línea en el mapa
    if (*rows >= *capacity) {
        *map = resize_map(*map, *capacity, *rows);
        if (!*map) {
            free(line);
            return (-1);  // Error al redimensionar el mapa
        }
        *capacity *= 2;
    }

    (*map)[*rows] = line;
    (*rows)++;
    return (1);  // Línea leída y almacenada correctamente
}
