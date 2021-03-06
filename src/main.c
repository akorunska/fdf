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
#include "parser.h"
#include "print_line.h"
#include "mlx.h"

void	call_hooks(t_params *params)
{
	mlx_hook(params->win, 17, 1L << 17, exit_x, (void*)params);
	mlx_key_hook(params->win, handle_keys, (void*)params);
}

// void	test_line(t_params *params)
// {
// 	t_point p0 = {500, 100};
// 	t_point p1 = {600, 400};
// 	print_line(params, &p1, &p0);
// }

int		main(int argc, char **argv)
{
	t_params params; 

	if (argc == 2)
	{
		ft_printf("attempting to read map [%s]\n", argv[1]);
		params.initial_map = parse_map(argv[1]);
		params.mlx = mlx_init();
		params.win = mlx_new_window(params.mlx, 1200, 900, "fdf");
		call_hooks(&params);

		// test_line(&params);

		mlx_loop(params.mlx);
	}
	else
	{
		ft_printf("invalid number of arguments.\n");
		ft_printf("usage: ./fdf map.fdf\n");
	}
}
