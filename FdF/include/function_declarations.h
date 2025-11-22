/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_declarations.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:07:42 by jambatt           #+#    #+#             */
/*   Updated: 2025/11/22 13:16:38 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ------------------ INIT UTILS ----------------------*/

void	init_fdf(t_fdf *fdf);
void	init_image(t_fdf *fdf);

/* ------------------ DEINIT UTILS ----------------------*/

void    deinit_mlx(t_fdf *fdf);
void    deinit_img(t_fdf *fdf);
void    deinit_map(t_fdf *fdf);
void    deinit_fdf(t_fdf *fdf);

/* ------------------ CLOSE UTILS ----------------------*/

void    exit_cleanly(t_fdf *fdf);
int		close_program(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);