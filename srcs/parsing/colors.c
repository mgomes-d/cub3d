/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 07:25:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 11:53:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ft_atoi_rgb is a custom version of atoi that checks if the number is
between 0 and 255 and skips the spaces before and after the number */
static int	ft_atoi_rgb(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (sign * res < INT_MIN || sign * res > INT_MAX)
			return (-1);
		if (sign * res < 0 || sign * res > 255)
			return (-1);
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i])
		return (-1);
	return (sign * res);
}

/* parse_colors uses bit shifting to convert 3 numbers rgb to an integer */
int	parse_colors(t_data *data, char *color)
{
	char	**rgb_array;
	int		red;
	int		green;
	int		blue;

	rgb_array = ft_split(color, ',');
	if (!rgb_array)
		exit_free_error(data, MSG_MALLOC_ERR);
	if (ft_array_len(rgb_array) != 3)
		exit_free_error(data, "RGB format is not valid!");
	red = ft_atoi_rgb(rgb_array[0]);
	green = ft_atoi_rgb(rgb_array[1]);
	blue = ft_atoi_rgb(rgb_array[2]);
	if (red == -1 || green == -1 || blue == -1)
		exit_free_error(data, "RGB format is not valid!");
	free_array(rgb_array);
	return ((red << 16) + (green << 8) + blue);
}
