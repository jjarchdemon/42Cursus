/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:13:31 by jambatt           #+#    #+#             */
/*   Updated: 2025/01/06 17:20:45 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
char	*line;
int	fd;

fd = open("./text.txt", O_RDONLY);
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
line = get_next_line(fd);
printf("%s", line);
return(0);
}
