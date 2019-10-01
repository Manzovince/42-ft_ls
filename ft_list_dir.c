/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:21:45 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/08/29 14:11:35 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft/includes/libft.h"

/* *****************************************************************************
** LIST DIRECTORIES
***************************************************************************** */
int		ft_list_dir(char *foldername)
{
	DIR				*dir;
	struct dirent	*sd;

	ft_putendl(foldername);

	if ((dir = opendir(foldername)) != NULL)
	{
		while ((sd = readdir(dir)) != NULL)
			ft_putendl(sd->d_name);
		closedir(dir);
	}
	else
		ft_putendl("Error.");
	return (0);
}

/* *****************************************************************************
** MAIN
***************************************************************************** */
int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("usage: ./ft_list_dir <foldername>");
	else
		ft_list_dir(av[1]);
	return (0);
}
