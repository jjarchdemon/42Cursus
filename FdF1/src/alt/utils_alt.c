/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:28:46 by jambatt           #+#    #+#             */
/*   Updated: 2025/03/18 11:31:14 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Initializes an fdf structure
fdf *create_fdf_data(void) {
    fdf *data = (fdf *)malloc(sizeof(fdf));
    if (!data)
        return (NULL);

    data->side.iso = 0;
    data->color = 0xffff;
    data->bvg_color = 0x1E1E1E;
    data->window.offset_x = (WIDTH / 3) + (WIDTH / 10);
    data->window.offset_y = (HEIGHT / 10);
    data->window.zoom = 0;
    data->mlx = NULL;
    data->wnd = NULL;
    data->img = NULL;
    data->address_data = NULL;
    data->map.render_map = NULL; // Initialize render_map to NULL
    return (data);
}

// Frees an array of strings
void free_string_array(char **arr) {
    if (!arr)
        return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

// Frees a 2D integer array
void free_int_array(int **arr) {
    if (!arr)
        return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

// Cleans up and exits the program
void cleanup_and_exit(fdf *data, int exit_code) {
    if (data) {
        if (data->mlx) {
            if (data->wnd)
                mlx_destroy_window(data->mlx, data->wnd);
            if (data->img)
                mlx_destroy_image(data->mlx, data->img);
            mlx_destroy_display(data->mlx);
            free(data->mlx);
        }
        free_int_array(data->map.render_map);
        free(data);
    }
    exit(exit_code);
}

/*
 * PROBLEMS:
 * Redundancy in ft_close and close_window: Both functions perform similar cleanup operations, but close_window has some extra steps like mlx_loop_end, ft_printf, and exit(0). We can likely merge these or refactor to remove the duplication.

Inconsistent NULL checks: Some functions check for NULL before freeing (e.g., ft_close, free_arr, free_map), while others don't. For consistency and safety, it's good to check for NULL before freeing memory.

ft_lst could be clearer: The name isn't very descriptive. Perhaps create_fdf_data or init_fdf_data would be better. Also, it initializes a lot of data struct members. Consider if that should be part of the main init.

SOLUTIONS:
Combined cleanup: I've created cleanup_and_exit to handle all the freeing and the exit. This reduces duplication. You can call this with different exit codes as needed.
Consistent freeing: The free_string_array and free_int_array functions now have a single responsibility, and NULL checks.
Renamed ft_lst: It's now create_fdf_data for clarity.
render_map initialization: create_fdf_data now initializes render_map to NULL, which is a good practice.
Removed ft_close and close_window: The functionality is now within cleanup_and_exit.
*/

