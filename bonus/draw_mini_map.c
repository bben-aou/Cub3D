/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:25:46 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/15 19:27:43 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

int	mouse_hook(int mouse, int x, int y, t_varb *var)
{
	(void)y;
	if (mouse == 1)
	{
		var->mouse.mouse_move = 1;
		var->mouse.mouse_stable = 0;
		var->mouse.x_mouse = x;
		var->mouse.y_mouse = y;
	}
	return (1);
}

int	ft_mouse_release(int mouse, int x, int y, t_varb *var)
{
	(void)x;
	(void)y;
	if (mouse == 1)
	{
		var->mouse.mouse_move = 0;
		var->mouse.mouse_stable = 1;
	}
	return (0);
}

void	draw_cube(t_varb *var, int width, int height, char *color)
{
	int	i;
	int	j;

	i = height;
	while (i < (height + T_S))
	{
		j = width;
		while (j < (width + T_S))
		{
			if (ft_strcmp_bn(color, "wall") == 0)
				my_img_pix_putb(var, j * 0.2, i * 0.2, 0x466986);
			else if (ft_strcmp_bn(color, "empty") == 0)
				my_img_pix_putb(var, j * 0.2, i * 0.2, 0xc9d9cf);
			j++;
		}
		i++;
	}
}

void	draw_player(t_varb *var)
{
	int	i;
	int	j;

	i = var->player->x;
	j = var->player->y;
	my_img_pix_putb(var, i * 0.2, j * 0.2, 0xFF0000);
}

void	draw_mini_map(t_varb *var)
{
	int	y;
	int	x;

	y = -1;
	while (++y < var->count_line)
	{
		x = -1;
		while (++x < ft_strlenb(var->map[y]))
		{
			if (var->map[y][x] == '1' || var->map[y][x] == ' ')
				draw_cube(var, (x * T_S), (y * T_S), "wall");
			else if (var->map[y][x] == '0')
				draw_cube(var, (x * T_S), (y * T_S), "empty");
			else if ((var->map[y][x] == 'N' || var->map[y][x] == 'S' \
				|| var->map[y][x] == 'E' || var->map[y][x] == 'W'))
				draw_cube(var, (x * T_S), (y * T_S), "empty");
			if (x == ft_strlenb(var->map[y]) - 1)
				while (++x < var->mlx->max_len)
					draw_cube(var, (x * T_S), (y * T_S), "wall");
		}
	}
	dda_line(var);
}
