/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:30:06 by akorunsk          #+#    #+#             */
/*   Updated: 2018/07/14 15:30:10 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "handlers.h"
#include "mlx.h"

void	call_hooks(t_params *params)
{
	mlx_hook(params->win, 17, 1L << 17, exit_x, (void*)params);
	mlx_key_hook(params->win, handle_keys, (void*)params);
}

int		main(int argc, char **argv)
{
	t_params params;

	if (argc == 2)
	{
		ft_printf("attempting to read map [%s]\n", argv[1]);
		params.mlx = mlx_init();
		params.win = mlx_new_window(params.mlx, 200, 200, "fdf");
		call_hooks(&params);
		mlx_loop(params.mlx);
	}
	else
	{
		ft_printf("invalid number of arguments.\n");
		ft_printf("usage: ./fdf map.fdf\n");
	}
}
