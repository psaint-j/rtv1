/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:57:01 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/03 18:16:28 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 800
# define HEIGHT 600
# define min(a,b) (((a) < (b)) ? (a) : (b))
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "./vector.h"
# include "./ray.h"
# include "./camera.h"
# include "./color.h"
# include "./light.h"
# include "./sphere.h"
# include "./plane.h"
# include "./material.h"

/*Delta second degre*/
typedef struct	s_delta{
	float		A;
	float		B;
	float		c;
}				t_delta;

/*params for screen of mlx*/
typedef struct	s_img
{
	void	*mlx;
	void	*win;
	char	*img;
	int		bpx;
	int		endian;
	int		size_line;
	void	*img_ptr;
	int		init;
	int		xWidth;
	int		yHeight;
}				t_img;

//createImage.c
void			saveppm(char *filename, unsigned char *img, int width, int height);
//mlxFonction.c
t_img			initImage(t_img s);
void			mlx_pixel_to_image(t_img *s, int x, int y, int color);
unsigned long	createRGB(int r, int g, int b);
void			mlx_pixel_to_image(t_img *s, int x, int y, int color);
#endif
