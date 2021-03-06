/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:02:30 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/03 18:12:24 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "../includes/rtv1.h"

typedef struct	s_sphere
{
	t_vector	pos;
	float		radius;
	int 		material;
}				t_sphere;

//sphereFonction.c
t_sphere	sphereConstruct(t_vector pos, float radius, int material);
bool		sphereIntersect(t_ray *r, t_sphere *s, float *t);
void		sphereDebug(t_sphere debug);
#endif
