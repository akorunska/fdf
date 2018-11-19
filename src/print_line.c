/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:35:24 by akorunsk          #+#    #+#             */
/*   Updated: 2018/07/14 18:35:26 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <math.h>

void swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int absolute(int val)
{
	return ((val > 0) ? val : -val);
}

int sign(int val) {
	if (val > 0)
		return (1);
	if (val < 0)
		return (-1);
	return (0);
}

void print_line(t_params *p, t_point *p0, t_point *p1)
{
	int	eps;
	int dx;
	int dy;
	int	index;
	int	sig_x;
	int sig_y;
	int swapped;
	t_point cur;

	index = 0;
	cur.x = p0->x;
	cur.y = p0->y;
	sig_x = sign(p1->x - p0->x);
	sig_y = sign(p1->y - p0->y);
	dx = absolute(p1->x - p0->x);
	dy = absolute(p1->y - p0->y);
	swapped = 0;
	if (dy > dx)
	{
		swap(&(dy), &(dx));
		swapped = 1;
	}
	eps = 2 * dx - dy;
	while (index < dx)
	{
		mlx_pixel_put(p->mlx, p->win, cur.x, cur.y, 0xFFFFFF);
		while (eps > -1)
		{
			eps = eps - 2 * dx;
			swapped ? (cur.x += sig_x) : (cur.y += sig_y);
			ft_printf("PIXEL %d %d\n", cur.x, cur.y);
		}
		eps = eps + 2 * dy;
		swapped ? (cur.y += sig_y) : (cur.x += sig_x);
		index++;
	}
	/*if (p0->x > p1->x)
	{
		swap(&(p0->x), &(p1->x));
		swap(&(p0->y), &(p1->y));
		swapped = 1;
	}
	if (absolute(dx) > absolute(dy))
		print_line_dx(p, p0, p1);
	else
		print_line_dy(p, p0, p1);
	if (swapped)
	{
		swap(&(p0->x), &(p1->x));
		swap(&(p0->y), &(p1->y));
	}*/
}