/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokada <rokada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:59:56 by rokada            #+#    #+#             */
/*   Updated: 2025/06/07 15:42:07 by rokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../all_libft/include/libft.h"
# include <signal.h>
# include "ft_printf.h"

# ifdef __linux__
#  define WAIT_TIME 1125
# endif

# ifdef __APPLE__
#  define WAIT_TIME 50
# endif

#endif