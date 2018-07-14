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

  // dx = x1 - x0
  // dy = y1 - y0
  // D = 2*dy - dx
  // y = y0

  // for x from x0 to x1
  //   plot(x,y)
  //   if D > 0
  //      y = y + 1
  //      D = D - 2*dx
  //   end if
  //   D = D + 2*dy

void print_line(t_params *p, t_point *p0, t_point *p1)
{
	int		dx;
	int		dy;
	int		d;
	t_point cur;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	d = 2 * dy - dx;
	cur.x = p0->x;
	cur.y = p0->y;
	while (cur.x < p1->x)
	{
		mlx_pixel_put(p->mlx, p->win, cur.x, cur.y, 0xFFFFFF);
		if (d > 0)
		{
			cur.y += 1;
			d -= 2 * dx;
		}
		else
			d += 2 * dy;
		cur.x++;
	}

}