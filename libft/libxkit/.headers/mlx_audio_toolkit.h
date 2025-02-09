/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_audio_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 00:51:34 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/13 11:29:27 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_AUDIO_TOOLKIT_H
# define MLX_AUDIO_TOOLKIT_H

# include "./libxkit.h"

void	play_sound(const char *sound_file);
void	stop_sound(void);
void	set_audio_volume(float volume);
void	pause_audio(void);
void	resume_audio(void);

#endif
