/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:16:07 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/04 14:19:37 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "./rtv1.h"

typedef struct	s_plane
{
	t_vector	normal;
	double		distance;
	t_color		color;
}				t_plane;

t_plane			planeConstruct(t_vector normal, double distance, t_color color);
double			planeIntersection(t_ray ray, t_plane plane);
void			planeDebug(t_plane debug);
#endif
