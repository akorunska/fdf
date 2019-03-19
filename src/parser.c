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

int is_valid_signed_decimal(char *coordinate)
{
	int		i;

	i = 0;
	if (coordinate[0] == '-' || coordinate[0] == '+')
		i++;
	while (coordinate[i] != 0)
	{
		if (!ft_isdigit(coordinate[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_hex(char *color)
{
	color = NULL;
	if (!color)
		return (1);
	return (1);
}

int validate_coordinate(char *coordinate)
{
	char	**splitted;
	int		i;

	splitted = ft_strsplit(coordinate, ',');
	i = 0;
	while (splitted[i] != 0)
		i++;
	if (--i > 1)
		return (0);
	if (!is_valid_signed_decimal(splitted[0]))
		return (0);
	if (i == 1)
		if (!is_valid_hex(splitted[1]))
			return (0);
	return (1);
}


int	count_digits_per_row(char *row)
{
	char	**digits;
	int		count;

	digits = ft_strsplit(row, ' ');
	count = 0;
	while (digits[count] != NULL)
	{
		if (validate_coordinate(digits[count]) == 0)
		{
			free(digits[count]);
			return (-1);
		}
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
	int		r;

	fd = open(file, O_RDONLY);
	if (fd > 2)
	{
		m->h = 0;
		row = NULL;
		r = 1;
		while (r)
		{
			r = get_next_line(fd, &row);
			if (!ft_strlen(row))
			{
				ft_strdel(&row);
				break;
			}
			current_w = count_digits_per_row(row);
			ft_strdel(&row);
			if (!(m->h))
				(m->w) = current_w;
			if (m->w != current_w)
				return (0);
			(m->h)++;
		}
		close(fd);
		if (m->w != -1)
		    return (1);
	}
	return (0);
}

t_map *parse_map(char *file)
{
	t_map	*map;
	int		valid;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return NULL;
	valid = fill_map_metrics(map, file);
	if (valid)
		ft_printf("the map has metrics: w -- %d; h -- %d", map->w, map->h);
	else
		ft_printf("the map is invalid\n");
	return map;
}
