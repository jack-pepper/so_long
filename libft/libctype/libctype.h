/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:25:28 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 14:18:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCTYPE_H
# define LIBCTYPE_H

/* STANDARD LIBRARIES */
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h> 
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>

/* LIBCTYPE */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_ispunct(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
