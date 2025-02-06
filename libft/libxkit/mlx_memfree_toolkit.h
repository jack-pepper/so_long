/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memfree_toolkit.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:12:24 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/06 13:33:20 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MEMFREE_TOOLKIT_H
# define MLX_MEMFREE_TOOLKIT_H

# include "./libxkit.h"

void    sl_memfree(t_state *state);
void    sl_destroy_imgs(t_state *state);
void    sl_free_map(t_state *state);

#endif
