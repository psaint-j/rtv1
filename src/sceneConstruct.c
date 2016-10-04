/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceneConstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:11:26 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/04 19:35:21 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(void)
{

	t_ray r;
	
	t_material materials[4];
	materials[0].diffuse.red = 0.36;
	materials[0].diffuse.green = 1;
	materials[0].diffuse.blue = 0.99;
	materials[0].reflection = 0.2;
	
	materials[1].diffuse.red = 1;
	materials[1].diffuse.green = 0;
	materials[1].diffuse.blue = 0.5;
	materials[1].reflection = 0.9;
	
	materials[2].diffuse.red = 0;
	materials[2].diffuse.green = 0;
	materials[2].diffuse.blue = 2;
	materials[2].reflection = 0.9;
	
	materials[3].diffuse.red = 1;
	materials[3].diffuse.green = 0.5;
	materials[3].diffuse.blue = 0;
	materials[3].reflection = 0.6;

	t_sphere spheres[1];
	spheres[0].pos.x = 350;
	spheres[0].pos.y = 300;
	spheres[0].pos.z = 0;
	spheres[0].radius = 150;
	spheres[0].material = 1;

	spheres[1].pos.x = 550;
	spheres[1].pos.y = 300;
	spheres[1].pos.z = 0;
	spheres[1].radius = 150;
	spheres[1].material = 2;

	t_light lights[4];
	
	lights[0].pos.x = 800;
	lights[0].pos.y = 600;
	lights[0].pos.z = -100;
	lights[0].intensity.red = 1;
	lights[0].intensity.green = 1;
	lights[0].intensity.blue = 1;
	
	lights[1].pos.x = 0;
	lights[1].pos.y = 600;
	lights[1].pos.z = -100;
	lights[1].intensity.red = 0.6;
	lights[1].intensity.green = 0.7;
	lights[1].intensity.blue = 0.9;

	lights[2].pos.x = 300;
	lights[2].pos.y = 700;
	lights[2].pos.z = -100;
	lights[2].intensity.red = 0.2;
	lights[2].intensity.green = 0.5;
	lights[2].intensity.blue = 1;

	lights[3].pos.x = 300;
	lights[3].pos.y = 700;
	lights[3].pos.z = -100;
	lights[3].intensity.red = 0.3;
	lights[3].intensity.green = 0.4	;
	lights[3].intensity.blue = 1;

	t_color gray;
	gray = colorConstruct(0.5, 0.5, 0.5);
	t_plane	plane;
	int 	x;
	int 	y;
	int 	j;
	int 	i;

	plane.normal = vect(0, 1, 0);
	plane.distance =  -1;
	plane.color = colorConstruct(0, 0, 0);
	
	unsigned char	image[3*WIDTH*HEIGHT];
	t_img			img;
	
	img.init = 0;
	img = initImage(img);
	y = -1;
	x = -1;
	//for(y=0;y<HEIGHT;y++){
	while (++y < HEIGHT){
		//while (++x < WIDTH){
		for(x=0;x<WIDTH;x++){
			
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
			
			do{
				/* Trouver l'intersection la plus proche */
				float t = 20000.0f;
				int currentSphere = -1;
				
				i = -1;
				//for(i = 0; i < 2; i++){
				while (++i < 2){
					if(sphereIntersect(&r, &spheres[i], &t))
						currentSphere = i;
				}
				if(currentSphere == -1) break;
				
				t_vector scaled = vectorScale(t, &r.dir);
				t_vector newStart = vectorAdd(&r.start, &scaled);
				// Trouver la normal du nouveau vect au point d'intersection
				t_vector n = vectorSub(&newStart, &spheres[currentSphere].pos);
				float temp = vectorDot(&n, &n);
				if(temp == 0) break;
				
				temp = 1.0f / sqrtf(temp);
				n = vectorScale(temp, &n);

				// Trouver le material pour determiner la couleur 
				t_material currentMat = materials[spheres[currentSphere].material];
				
				// Trouver la valeur de la lumir a ce point
				//for(j=0; j < 4; j++){
			    j = 0;
				while (j++ < 4)
				{
					t_light currentLight = lights[j];
					t_vector dist = vectorSub(&currentLight.pos, &newStart);
					if(vectorDot(&n, &dist) <= 0.0f) 
						j++;
						//continue;
					float t = sqrtf(vectorDot(&dist,&dist));
					if(t <= 0.0f)
						j++; 
						//continue;
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

			}while((coef > 0.0f) && (level < 15));
			mlx_pixel_to_image(&img, x, y, createRGB((unsigned char)min(red*255.0f, 255.0f), (unsigned char)min(green*255.0f, 255.0f), (unsigned char)min(blue*255.0f, 255.0f)));
			image[(x + y * WIDTH) * 3 + 0] = (unsigned char)min(red*255.0f, 255.0f);
			image[(x + y * WIDTH) * 3 + 1] = (unsigned char)min(green*255.0f, 255.0f);
			image[(x + y * WIDTH) * 3 + 2] = (unsigned char)min(blue*255.0f, 255.0f);
		}
	}
	
	savePPM("image.ppm", image, WIDTH, HEIGHT);
	mlx_put_image_to_window(img.mlx, img.win, img.img_ptr, 0, 0);
	ft_putstr("finishing rendering\n");
	mlx_loop(img.mlx);
	return (0);
}
