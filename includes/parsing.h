/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:30:33 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/27 07:31:28 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_data	t_data;

/* args */
int		check_args_nb(int ac);
int		check_map_name(char **av);
/* colors */
int		parse_colors(t_data *data, char *color);
/* initialization */
void	parsing_tables_initialization(t_data *data);
/* map checks */
void	check_is_valid_map(t_data *data);
/* map closed */
int		is_closed_map(char **map);
/* map */
void	parse_map(t_data *data, char *line);
/* parsing */
void	init_parsing(t_data *data, int ac, char **av);
/* player */
void	init_player_infos(t_data *data);

#endif
