/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:10:36 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/04 14:21:32 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(void)
{
//	Check file
//	bool		hit;
//	unsigned char	im[WIDTH * HEIGHT * 3];
//	t_img		img;
	int			x;
	int			y;
	t_vector	X;
	t_vector	Y;
	t_vector	Z;
	t_vector	look_at;
	t_vector	diff_btw;
	t_vector	camdir;
	t_vector	camright;
	t_vector	tmp;	
	t_vector	camdown;
	t_camera	scene_cam;
	t_light		scene_light;
	t_sphere	scene_sphere;
	t_color		white_light;
	t_color		pretty_green;
	t_color		gray;
	t_color		black;
	t_color		marroon;
	t_plane		scene_plane;
	t_ray		scene_ray;
	t_vector	scaled;

	y = 0;
	x = 0;

	X = vect(3, 1, 2);
	Y = vect(0, 1, 0);
	Z = vect(0, 0, 1);

	white_light = colorConstruct(1.0, 1.0, 1.0);
	pretty_green = colorConstruct(0.5, 1.0, 0.5);
	gray = colorConstruct(0.5, 0.5, 0.5);
	black = colorConstruct(0.0, 0.0, 0.0);
	marroon = colorConstruct(0.5, 0.25, 0.25);
	scene_cam.campos = vect(-7, 10, -10);

	look_at = vect(1, 4, 5);
	diff_btw = vect((scene_cam.campos.x - look_at.x), (scene_cam.campos.y - look_at.y), (scene_cam.campos.z - look_at.z));
	tmp = vectorNegative(&diff_btw);
	camdir = (vectorNormalize(&tmp));
	tmp = vectorCross(&Y, &camdir);
	camright = vectorNormalize(&tmp);
	camdown = vectorCross(&camright, &camdir);
	scene_cam = camConstruct(vect(3, 1.5, -4), camdir, camright, camdown);
	scene_light = lightConstruct(vect(-7, 10, -10), white_light);
	scene_sphere = sphereConstruct(O, 1, pretty_green);
	scene_plane = planeConstruct(Y, -1, marroon);
	scene_ray = rayConstruct(vect(0, 0, 0), vect(1, 0, 1));
	planeDebug(scene_plane);
	camDebug(scene_cam);
	sphereDebug(scene_sphere);
	rayDebug(scene_ray);

	scaled = vectorScale(t, &scene_ray.dir);
	/*while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			hit = intersectSphere(&r, &s, &t);
			if (hit)
			{
				mlx_pixel_to_image(&img, x, y, createRGB(color.red, color.green, color.blue));
				im[(x + y * WIDTH) * 3 + 0] = 126;
				im[(x + y * WIDTH) * 3 + 1] = 0;
				im[(x + y * WIDTH) * 3 + 2] = 0;
			}
			else
			{
				mlx_pixel_to_image(&img, x, y, 0);
				im[(x + y * WIDTH) * 3 + 0] = 0;
				im[(x + y * WIDTH) * 3 + 1] = 0;
				im[(x + y * WIDTH) * 3 + 2] = 0;
			}
			x++;
		}
		x = 0;
		y++;
	}
//	mlx_put_image_to_window(img.mlx, img.win, img.img_ptr, 0, 0);
//	ft_putstr("finishing rendering\n");
//	mlx_loop(img.mlx);*/
	return (0);
}
