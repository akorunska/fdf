/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:48:27 by akorunsk          #+#    #+#             */
/*   Updated: 2018/07/14 16:48:29 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"


void exit_esc(void *params)
{
	if (((t_params*)params)->initial_map)
		ft_memdel((void**)&(((t_params*)params)->initial_map));
	exit(1);
}