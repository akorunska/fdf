/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:33:51 by akorunsk          #+#    #+#             */
/*   Updated: 2018/07/14 18:33:54 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

int fill_map_metrics(t_map *m, char *file)
{
	int		fd;
	// int		current_w;
	char	*row;

	fd = open(file, O_RDONLY);
	if (fd > 2)
	{
		m->h = 0;
		while (get_next_line(fd, &row))
		{
			(m->h)++;
			free(row);
		}
		close(fd);
	}
	return (0);
}

t_map *parse_map(char *file)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return NULL;
	fill_map_metrics(map, file);
	return map;
}
