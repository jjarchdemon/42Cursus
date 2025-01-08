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
if (fd < 0)
{
	printf("Error opening file");
	return(1);
}
line = get_next_line(fd);
while (line)
{
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
}
free(line);
close(fd);
return(0);
}
