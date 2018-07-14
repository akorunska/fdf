/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:31:04 by akorunsk          #+#    #+#             */
/*   Updated: 2018/07/14 15:31:07 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_params
{
	void	*mlx;
	void	*win;
}				t_params;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

#endif
