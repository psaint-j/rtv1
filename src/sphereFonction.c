/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphereFonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:07:27 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 18:25:46 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_sphere	sphereConstruct(t_vector pos, float radius, t_color color)
{
	t_sphere	result;
	result.pos = pos;
	result.radius = radius;
	result.color = color;
	return (result);
}

void	sphereDebug(t_sphere debug)
{
	printf("spherePos(%f, %f, %f)\n",debug.pos.x, debug.pos.y, debug.pos.z);
	printf("sphereRadius(%f)\n",debug.radius);
	printf("sphereColor\n");
	colorDebug(debug.color);
}
