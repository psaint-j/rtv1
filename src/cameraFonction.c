/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameraFonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:59:44 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 16:58:18 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_camera	camConstruct(t_vector campos, t_vector camdir, t_vector camright, t_vector camdown)
{
	t_camera	result;
	result.campos = campos;
	result.camdir = camdir;
	result.camright = camright;
	result.camdown = camdown;
	return (result);
}

void	camDebug(t_camera debug)
{
	printf("camPos(%f, %f, %f)\n",debug.campos.x, debug.campos.y, debug.campos.z);
	printf("camDir(%f, %f, %f)\n",debug.camdir.x, debug.camdir.y, debug.camdir.z);
	printf("camRight(%f, %f, %f)\n",debug.camright.x, debug.camright.y, debug.camright.z);
	printf("camDown(%f, %f, %f)\n",debug.camdown.x, debug.camdown.y, debug.camdown.z);
}
