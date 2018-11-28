/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:43:34 by akorunsk          #+#    #+#             */
/*   Updated: 2018/07/14 18:43:37 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H	

typedef struct	s_parse_error
{
	int		line;
	char	error_type;
}				t_parse_error;

t_map *parse_map(char *file);

#endif
