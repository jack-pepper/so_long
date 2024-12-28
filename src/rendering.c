/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:03:23 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/29 00:12:37 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int     render(t_env *env)
{
        render_background(env);
//      render_map(env, img);
//      render_player(env, img);
//      render_moves(env, img);
        return (0);
}

void    render_background(t_env *env)
{
        mlx_put_image_to_window(env->mlx, env->win, env->canvas->img, 0, 0);
}
