/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:12:18 by jambatt           #+#    #+#             */
/*   Updated: 2025/11/22 12:25:19 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include "macros.h"
# include "key_codes.h"
#include "ft_printf/ft_printf.h"
//# include "libft/libft.h"
# include "structs.h"
# include "function_declarations.h"

# ifdef __APPLE__
#  include "minilibx-mac/mlx.h"
# else
#  include "minilibx-linux/mlx.h"
# endif

# endif