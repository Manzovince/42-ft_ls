/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:17:58 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/09/28 13:40:49 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

/*
** -------------------------------- LIBRAIRIES ---------------------------------
*/

# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>

# include <stdio.h>
# include "../libft/includes/libft.h"

/*
** --------------------------------- DEFINES -----------------------------------
*/

# define PF_BUFFSIZE		2048
# define MASK(value, mask)	((value & mask) == mask)

/*
** ------------------------------- FLAGS MASK ----------------------------------
*/



/*
** -------------------------------- STRUCTURES ---------------------------------
*/



/*
** ------------------------------- MAIN FUNCTIONS ------------------------------
*/

int		ft_ls(char *arg);
void	ls_error(char *str);

/*
** ------------------------------- ERROR FUNCTIONS -----------------------------
*/

void	ls_error(char *str);


#endif
