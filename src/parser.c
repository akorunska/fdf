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
#include <unistd.h>
#include "libft.h"
#include "fdf.h"

int	count_digits_per_row(char *row)
{
	char **digits;
	int count;

	digits = ft_strsplit(row, ' ');
	count = 0;
	while (digits[count] != NULL)
	{
		free(digits[count]);
		count++;
	}
	free(digits);
	return (count);
}

int fill_map_metrics(t_map *m, char *file)
{
	int		fd;
	int		current_w;
	char	*row;

	fd = open(file, O_RDONLY);
	if (fd > 2)
	{
		m->h = 0;
		while (get_next_line(fd, &row))
		{
			current_w = count_digits_per_row(row);
			free(row);
			if (!(m->h))
				(m->w) = current_w;
			if (m->w != current_w)
				return (0);
			(m->h)++;
		}
		close(fd);
		return (1);
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
	ft_printf("the map has metrics: w -- %d; h -- %d", map->w, map->h);
	return map;
}
