/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphereFonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:07:27 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/05 17:26:35 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_sphere	sphereConstruct(t_vector pos, float radius, int material)
{
	t_sphere	result;
	result.pos = pos;
	result.radius = radius;
	result.material = material;
	return (result);
}

bool	sphereIntersect(t_ray *r, t_sphere *s, float *t)
{
	float	A;
	float	B;
	float	C;
	float	delta;
	float	sqrtdelta;
	float	x1;
	float	x2;
	bool	result;

	result = false;
	t_vector dist = vectorSub(&r->start, &s->pos);
	A = vectorDot(&r->dir, &r->dir);
	B = 2 * vectorDot(&r->dir, &dist);
	C = vectorDot(&dist, &dist) - (s->radius * s->radius);
	delta = B * B - 4 * A * C;
	if (delta < 0)
		return result;
	else
	{
		sqrtdelta = sqrt(delta);
		x1 = (-B + sqrtdelta)/(2);
		x2 = (-B - sqrtdelta)/(2);
		if (x1 > x2)
			x1 = x2;
		if ((x1 > 0.001f) && (x1 < *t))
		{
			*t = x1;
			result = true;
		}
		else
			result = false;
	}
	return result;
}

void	sphereDebug(t_sphere debug)
{
	printf("spherePos(%f, %f, %f)\n",debug.pos.x, debug.pos.y, debug.pos.z);
	printf("sphereRadius(%f)\n",debug.radius);
	printf("sphereMaterial(%d)\n", debug.material);
}