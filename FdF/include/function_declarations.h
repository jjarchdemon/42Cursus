/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_declarations.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:07:42 by jambatt           #+#    #+#             */
/*   Updated: 2025/12/23 15:07:09 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ------------------ INIT UTILS ----------------------*/

void	init_fdf(t_fdf *fdf);
void	init_img(t_fdf *fdf);

/* ------------------ MLX UTILS ----------------------*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	create_blank_image(t_fdf *fdf);

/* ------------------ PARSING ----------------------*/
void	parse_map(char *filename, t_fdf *fdf);

/* ------------------ DEINIT UTILS ----------------------*/

void	deinit_mlx(t_fdf *fdf);
void	deinit_img(t_fdf *fdf);
void	deinit_map(t_fdf *fdf);
void	deinit_fdf(t_fdf *fdf);

/* ------------------ CLOSE UTILS ----------------------*/

void	exit_cleanly(t_fdf *fdf);
int		close_program(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);

/* ------------------ ERROR UTILS ----------------------*/
void	exit_with_error(t_fdf *fdf, char *error_msg);

/* ------------------ DEBUG  ----------------------*/

void	print_z_map(t_fdf *fdf);