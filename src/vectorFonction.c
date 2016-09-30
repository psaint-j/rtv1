/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorFonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:02:29 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 19:40:23 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector vectorSub(t_vector *v1, t_vector *v2)
{
	t_vector result;
	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

float	vectorDot(t_vector *v1, t_vector *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + ( v1->z * v2->z));
}

t_vector	vectorScale(float c, t_vector *v)
{
	t_vector	result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}

t_vector	vectorAdd(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

double		vectorMagnitude(t_vector *v)
{
	return (sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

t_vector	vectorNormalize(t_vector *v)
{
	t_vector	result;
	double		magnitude;

	magnitude = vectorMagnitude(v);
	result.x = v->x/magnitude;
	result.y = v->y/magnitude;
	result.z = v->z/magnitude;
	return (result);
}

t_vector	vectorNegative(t_vector *v)
{
	t_vector	result;
	result.x = -(v->x);
	result.y = -(v->y);
	result.z = -(v->z);
	return (result);
}

t_vector	vectorCross(t_vector *v1, t_vector *v2)
{
	t_vector	result;

	result.x = (v1->y * v2->z) - (v1->z * v2->y);
	result.y = (v1->z * v2->x) - (v1->x * v2->z);
	result.z = (v1->x * v2->y) - (v1->y * v2->x);
	return (result);
}

t_vector	vect(float x, float y, float z)
{
	t_vector	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

void		vectorDebug(t_vector debug)
{
	printf("vector(%f, %f, %f)\n", debug.x, debug.y,debug.z);
}
