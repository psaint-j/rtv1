/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:48:49 by psaint-j          #+#    #+#             */
/*   Updated: 2016/10/03 16:54:12 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
#include "./rtv1.h"

typedef	struct	s_material
{
	t_color	diffuse;
	float		reflection;
}				t_material;

t_material		materialConstruct(t_color diffuse, float reflection);
void			materialDebug(t_material debug);
#endif