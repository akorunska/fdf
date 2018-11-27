/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:33:51 by akorunsk          #+#    #+#             */
/*   Updated: 2018/07/14 16:33:54 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "handlers.h"
#include "fdf.h"

int exit_x(void *params)
{
	if (((t_params*)params)->initial_map)
		ft_memdel((void**)&(((t_params*)params)->initial_map));
	exit(1);
	return (0);
}

int handle_keys(int key, void *params)
{
	if (key == 53)
		exit_esc(params);

	//
	if (params)
		return 0;
	return 0;
}