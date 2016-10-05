/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceneConstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:11:26 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/05 19:01:12 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(void)
{

	t_ray r;
	
	t_material materials[5];
	materials[0] = materialConstruct(colorConstruct(0.9, 0.4, 0.6), 0.2);
	materials[1] = materialConstruct(colorConstruct(1, 0, 0.5), 0.9);
	materials[2] = materialConstruct(colorConstruct(0.9, 0.5, 0.1), 0.5);
	materials[3] = materialConstruct(colorConstruct(0, 0.8, 0), 0.6);
	materials[4] = materialConstruct(colorConstruct(0.9, 0, 0.9), 0.5);

	t_sphere spheres[3];
	spheres[0] = sphereConstruct(vect(450, 300, 0), 70, 4);
	spheres[1] = sphereConstruct(vect(550, 300, 0), 70, 2);
	spheres[2] = sphereConstruct(vect(470, 170, 0), 70, 3);

	t_light lights[4];
	lights[0] = lightConstruct(vect(300, 600, -400), colorConstruct(1, 1, 1));
	lights[1] = lightConstruct(vect(0, 0, -100), colorConstruct(0.6, 0.7, 0.9));
	lights[2] = lightConstruct(vect(0, 0, -100), colorConstruct(0.2, 0.5, 1));
	lights[3] = lightConstruct(vect(0, 0, -100), colorConstruct(0.3, 0.4, 1));

	t_color gray;
	gray = colorConstruct(0.5, 0.5, 0.5);
	t_plane	plane;
	int 	x;
	int 	y;
	int 	j;
	int 	i;

	plane = planeConstruct(vect(0, 1, 0), -1, colorConstruct(0, 0.8, 0));
	unsigned char	image[3 * WIDTH * HEIGHT];
	t_img			img;
	
	img.init = 0;
	img = initImage(img);
	y = -1;
	x = -1;
	while (++y < HEIGHT){
		x = -1;
		while (++x < WIDTH){
			
			float red = 0;
			float green = 0;
			float blue = 0;
			
			int level = 0;
			float coef = 1.0;
			
			r.start.x = x;
			r.start.y = y;
			r.start.z = -2000;
			
			r.dir.x = 0;
			r.dir.y = 0;
			r.dir.z = 1;
			
			while((coef > 0.0f) && (level < 15)){
				/* Trouver l'intersection la plus proche */
				float t = 20000.0f;
				int currentSphere = -1;
				
				i = -1;
				while (++i < 3	){
					if(sphereIntersect(&r, &spheres[i], &t))
						currentSphere = i;
				}
				if(currentSphere == -1)
					break;
				t_vector scaled = vectorScale(t, &r.dir);
				t_vector newStart = vectorAdd(&r.start, &scaled);
				// Trouver la normal du nouveau vect au point d'intersection
				t_vector n = vectorSub(&newStart, &spheres[currentSphere].pos);
				float temp = vectorDot(&n, &n);
				if(temp == 0)
					break;
				temp = 1.0f / sqrtf(temp);
				n = vectorScale(temp, &n);

				// Trouver le material pour determiner la couleur 
				t_material currentMat = materials[spheres[currentSphere].material];
				
				// Trouver la valeur de la lumir a ce point
			    j = -1;
				while (j++ < 1)
				{
					t_light currentLight = lights[j];
					t_vector dist = vectorSub(&currentLight.pos, &newStart);
					if(vectorDot(&n, &dist) <= 0.0f) 
						continue;
					float t = sqrtf(vectorDot(&dist,&dist));
					if(t <= 0.0f)
						continue;
					t_ray lightRay;

					lightRay.start = newStart;
					lightRay.dir = vectorScale((1/t), &dist);
					
					// Lambert diffusion
					float lambert = vectorDot(&lightRay.dir, &n) * coef; 
					red += lambert * currentLight.intensity.red * currentMat.diffuse.red;
					green += lambert * currentLight.intensity.green * currentMat.diffuse.green;
					blue += lambert * currentLight.intensity.blue * currentMat.diffuse.blue;
				}
				//Iterer sur la reflection
				coef *= currentMat.reflection;
				
				//Reflexion ray start et direction
				r.start = newStart;
				float reflect = 2.0f * vectorDot(&r.dir, &n);
				t_vector tmp = vectorScale(reflect, &n);
				r.dir = vectorSub(&r.dir, &tmp);

				level++;

			}
			//while((coef > 0.0f) && (level < 15));
			mlx_pixel_to_image(&img, x, y, createRGB((unsigned char)min(red*255.0f, 255.0f), (unsigned char)min(green*255.0f, 255.0f), (unsigned char)min(blue*255.0f, 255.0f)));
			image[(x + y * WIDTH) * 3 + 0] = (unsigned char)min(red*255.0f, 255.0f);
			image[(x + y * WIDTH) * 3 + 1] = (unsigned char)min(green*255.0f, 255.0f);
			image[(x + y * WIDTH) * 3 + 2] = (unsigned char)min(blue*255.0f, 255.0f);
		}
	}
	
	savePPM("image.ppm", image, WIDTH, HEIGHT);
	mlx_put_image_to_window(img.mlx, img.win, img.img_ptr, 0, 0);
	materialDebug(materials[3]);
	mlx_loop(img.mlx);
	return (0);
}
