/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxFonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 17:52:48 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/03 18:16:21 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		mlx_pixel_to_image(t_img *s, int x, int y, int color)
{
	unsigned char	color1;
	unsigned char	color2;
	unsigned char	color3;

	color1 = color >> 0;
	color2 = color >> 8;
	color3 = color >> 16;
	s->img[y * s->size_line + x * s->bpx / 8] = color1;
	s->img[y * s->size_line + x * s->bpx / 8 + 1] = color2;
	s->img[y * s->size_line + x * s->bpx / 8 + 2] = color3;
}

unsigned long	createRGB(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

t_img		initImage(t_img s)
{
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, WIDTH, HEIGHT, "RTV1");
	s.img_ptr = mlx_new_image(s.mlx, WIDTH, HEIGHT);
	s.img = mlx_get_data_addr(s.img_ptr, &s.bpx, &s.size_line, &s.endian);
	return (s);
}

void	saveppm(char *filename, unsigned char *img, int width, int height)
{
	FILE	*f;

	f = fopen(filename, "w");
	fprintf(f, "P6 %d %d %d\n", width, height, 255);
	fwrite(img, 3, width*height, f);
	fclose(f);
}