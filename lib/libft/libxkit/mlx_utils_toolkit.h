/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 00:54:41 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 18:55:22 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_TOOLKIT_H
# define MLX_UTILS_TOOLKIT_H

# include "./libxkit.h"

void	mlx_show(t_xvar *xvar, t_win_list *win, XImage *img, t_pos pos);
int     ft_error(int return_val, char *error_msg);

#endif
