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

void exit_esc(void *params)
{
	params = NULL;
	exit(1);
}