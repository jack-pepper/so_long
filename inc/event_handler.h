/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:57:35 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/05 21:20:24 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLER_H
# define EVENT_HANDLER_H

# include "./so_long.h"

int on_destroy(t_env *env);
int on_keypress(int keysym, t_game *game);

#endif
