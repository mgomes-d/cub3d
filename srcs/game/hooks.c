/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:11:19 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/02 18:26:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* close_window closes the game and frees all allocated memory */
int	close_window(t_data *data)
{
	ft_putendl_fd("Game closed.", STDOUT_FILENO);
	mlx_destroy_window(data->mlx, data->win);
	free_everythings(data);
	exit(EXIT_SUCCESS);
}

/* key_pressed activates a boolean when a key is pressed */
int	key_pressed(int key, t_data *data)
{
	if (key == KEY_ESC)
		close_window(data);
	if (key == KEY_W)
		data->key[W] = true;
	if (key == KEY_A)
		data->key[A] = true;
	if (key == KEY_S)
		data->key[S] = true;
	if (key == KEY_D)
		data->key[D] = true;
	if (key == KEY_L)
		data->key[L] = true;
	if (key == KEY_R)
		data->key[R] = true;
	if (key == KEY_SHIFT)
		data->key[SHIFT] = true;
	return (0);
}

/* key_release disables a boolean when a key is released */
int	key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->key[W] = false;
	if (key == KEY_A)
		data->key[A] = false;
	if (key == KEY_S)
		data->key[S] = false;
	if (key == KEY_D)
		data->key[D] = false;
	if (key == KEY_L)
		data->key[L] = false;
	if (key == KEY_R)
		data->key[R] = false;
	if (key == KEY_SHIFT)
		data->key[SHIFT] = false;
	return (0);
}

/* mouse_rotate updates the player's camera plane */
int	mouse_rotate(int x, int y, t_data *data)
{
	double	pitch;
	int		direction;

	(void) y;
	mlx_mouse_hide();
	direction = 1;
	if (x > data->win_w / 2)
	{
		pitch = (x - (data->win_w / 2)) * 0.08 / 60.0;
		direction = 0;
	}
	if (x < data->win_w / 2)
		pitch = ((data->win_w / 2) - x) * 0.08 / 60.0;
	if (x != data->win_w / 2)
		update_angle_mouse(data, &data->ray, direction, pitch);
	mlx_mouse_move(data->win, data->win_w / 2, data->win_h / 2);
	return (0);
}
