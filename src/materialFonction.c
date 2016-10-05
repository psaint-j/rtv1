/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materialFonction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:17:01 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/05 17:20:18 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_material		materialConstruct(t_color diffuse, float reflection)
{
	t_material	result;
	result.diffuse = diffuse;
	result.reflection = reflection;
	return (result);
}

void			materialDebug(t_material debug)
{
	printf("materialDiffuse(%f, %f, %f)\n",debug.diffuse.red, debug.diffuse.green, debug.diffuse.blue);
	printf("materialReflection(%f)\n",debug.reflection);
}
