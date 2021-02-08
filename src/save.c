/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safernan <safernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:42:26 by safernan          #+#    #+#             */
/*   Updated: 2021/02/08 19:42:28 by safernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_save(char **av, t_stru *stru)
{
	if (av[2])
	{
		if (!ft_strncmp(av[2], "--save", 6))
			stru->save = 1;
		else
		{
			ft_putstr_fd("Error\nUnknown second argument\n", 1);
			return (1);
		}
	}
	return (0);
}

void	bpm_init(t_stru *stru, t_save *save)
{
	save->size = 54 + 4 * stru->screen_width * stru->screen_height;
	save->zero = 0;
	save->offset_begin = 54;
	save->header_bytes = 40;
	save->plane = 1;
	save->bpp = 32;
	save->fd = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (save->fd == -1)
		ft_putstr_fd("Error\nCan't create image\n", 1);
}

void	bpm_pixels(t_stru *stru, int fd)
{
	int		y;
	int		x;
	int		l;

	y = 0;
	while (y < stru->screen_height)
	{
		x = 0;
		l = stru->screen_width * (stru->screen_height - y);
		while (x < stru->screen_width)
		{
			write(fd, &stru->pixels[l * 4], 4);
			l++;
			x++;
		}
		y++;
	}
}

void	save(t_stru *stru)
{
	t_save	save;

	bpm_init(stru, &save);
	write(save.fd, "BM", 2);
	write(save.fd, &save.size, sizeof(int));
	write(save.fd, &save.zero, sizeof(int));
	write(save.fd, &save.offset_begin, sizeof(int));
	write(save.fd, &save.header_bytes, sizeof(int));
	write(save.fd, &stru->screen_width, sizeof(int));
	write(save.fd, &stru->screen_height, sizeof(int));
	write(save.fd, &save.plane, sizeof(short int));
	write(save.fd, &save.bpp, sizeof(short int));
	write(save.fd, &save.zero, sizeof(int));
	write(save.fd, &save.zero, sizeof(int));
	write(save.fd, &save.zero, sizeof(int));
	write(save.fd, &save.zero, sizeof(int));
	write(save.fd, &save.zero, sizeof(int));
	write(save.fd, &save.zero, sizeof(int));
	bpm_pixels(stru, save.fd);
	close(save.fd);
}
