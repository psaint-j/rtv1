/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightFonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:15:51 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 18:25:24 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_light		lightConstruct(t_vector pos, t_color intensity)
{
	t_light	result;
	result.pos = pos;
	result.intensity = intensity;
	return (result);
}

void		lightDebug(t_light debug)
{
	printf("lightPos(%f, %f, %f)\n",debug.pos.x, debug.pos.y, debug.pos.z);
	printf("lightIntensity(%f, %f, %f)\n",debug.intensity.red, debug.intensity.green, debug.intensity.blue);
}
