/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planeFonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:23:12 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/04 14:19:18 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/rtv1.h"

t_plane		planeConstruct(t_vector normal, double distance, t_color color)
{
	t_plane		result;
	result.normal = normal;
	result.distance = distance;
	result.color = color;
	return (result);
}

t_vector	planeNormalAt(t_plane plane)
{
	return (plane.normal);
}

double		planeIntersection(t_ray ray, t_plane plane)
{		
	double		b;
	double		a;
	t_vector	tmp;

	a = vectorDot(&ray.dir, &plane.normal);
	if (a == 0)
	{
		//ray is parallel to plane
		return (-1);
	}
	else
	{
		tmp = vectorScale(plane.distance, &plane.normal);
		tmp = vectorNegative(&tmp);
		tmp = vectorAdd(&ray.start, &tmp);
		b = vectorDot(&plane.normal, &tmp);
		return (-1 * b / a);
	}
}

void		planeDebug(t_plane debug)
{
	printf("PlaneNormal(%f, %f, %f)\n",debug.normal.x, debug.normal.y, debug.normal.z);
	printf("planeDistance(%f)\n",debug.distance);
	printf("planeColor\n");
	colorDebug(debug.color);
}
