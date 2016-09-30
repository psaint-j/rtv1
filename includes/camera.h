/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:36:29 by psaint-j          #+#    #+#             */
/*   Updated: 2016/09/28 17:14:18 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
#include "./rtv1.h"

typedef struct	s_camera
{
	t_vector	campos;
	t_vector	camdir;
	t_vector	camright;
	t_vector	camdown;
}				t_camera;
//CamFonction.c
t_camera		camConstruct(t_vector campos, t_vector camdir, t_vector camright, t_vector camdown);
void			camDebug(t_camera debug);
#endif
