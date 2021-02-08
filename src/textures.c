/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:42:40 by safernan          #+#    #+#             */
/*   Updated: 2021/02/08 19:42:43 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		get_data(t_stru *stru)
{
	int i;

	i = 0;
	while (i < 5)
	{
		stru->img[i].pixels = mlx_get_data_addr(stru->img[i].img_ptr,
		&(stru->img[i].bpp), &(stru->img[i].sizeline), &(stru->img[i].endian));
		i++;
	}
	i = 0;
	while (i < 5)
		if (!stru->img[i++].pixels)
			return (1);
	return (0);
}

int		get_ptrs(t_stru *stru)
{
	int i;

	i = 0;
	stru->img[0].img_ptr = mlx_xpm_file_to_image(stru->mlx_ptr,
							stru->path_north, &stru->img[0].width,
							&stru->img[0].height);
	stru->img[1].img_ptr = mlx_xpm_file_to_image(stru->mlx_ptr,
							stru->path_south, &stru->img[1].width,
							&stru->img[1].height);
	stru->img[2].img_ptr = mlx_xpm_file_to_image(stru->mlx_ptr,
							stru->path_est, &stru->img[2].width,
							&stru->img[2].height);
	stru->img[3].img_ptr = mlx_xpm_file_to_image(stru->mlx_ptr,
							stru->path_west, &stru->img[3].width,
							&stru->img[3].height);
	stru->img[4].img_ptr = mlx_xpm_file_to_image(stru->mlx_ptr,
							stru->path_sprite, &stru->img[4].width,
							&stru->img[4].height);
	while (i < 5)
		if (!stru->img[i++].img_ptr)
			return (1);
	return (0);
}

void	init_dimensions(t_stru *stru)
{
	stru->img[0].width = 225;
	stru->img[0].height = 225;
	stru->img[1].width = 275;
	stru->img[1].height = 183;
	stru->img[2].width = 512;
	stru->img[2].height = 341;
	stru->img[3].width = 290;
	stru->img[3].height = 174;
	stru->img[4].width = 1280;
	stru->img[4].height = 720;
}

int		init_textures(t_stru *stru)
{
	init_dimensions(stru);
	if (get_ptrs(stru))
		return (1);
	if (get_data(stru))
		return (1);
	return (0);
}
