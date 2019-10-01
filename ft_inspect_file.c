/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:49:11 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/08/29 14:11:03 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

/* *****************************************************************************
** GET ABSOLUTE PATH TO FILE
***************************************************************************** */
void	ft_get_file_abs_path(char *filename, struct stat stbuf)
{
	ft_putstr("Asbolute Path: ");
	ft_putendl(realpath(filename, NULL));
}

/* *****************************************************************************
** GET FILE NAME
***************************************************************************** */
void	ft_get_file_name(char *filename)
{
	int		i;

	i = -1;
	ft_putstr("Filename: ");
	ft_putendl(filename);
}

/* *****************************************************************************
** GET FILE TYPE
***************************************************************************** */
void	ft_get_file_type(char *filename, struct stat stbuf)
{
	ft_putstr("Type: ");
	if (S_ISDIR(stbuf.st_mode))
		ft_putendl("Folder");
	else if (S_ISREG(stbuf.st_mode))
		ft_putendl("Regular File");
}

/* *****************************************************************************
** GET FILE PERMISSIONS
***************************************************************************** */
void	ft_get_file_perms(char *filename, struct stat stbuf)
{
	ft_putstr("Permissions: ");
	ft_putchar((stbuf.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((stbuf.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((stbuf.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((stbuf.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((stbuf.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((stbuf.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((stbuf.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((stbuf.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((stbuf.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putchar('\n');
}

/* *****************************************************************************
** GET FILE LINKS
***************************************************************************** */
void	ft_get_file_links(char *filename, struct stat stbuf)
{
	ft_putstr("Links: ");
	ft_putnbr(stbuf.st_nlink);
	ft_putchar('\n');
}

/* *****************************************************************************
** GET FILE OWNER
***************************************************************************** */
void	ft_get_file_owner(char *filename, struct stat stbuf)
{
	struct passwd	*pw;

	ft_putstr("Owner: ");
	pw = getpwuid(stbuf.st_uid);
	ft_putstr(pw->pw_name);
	ft_putchar('\n');
}

/* *****************************************************************************
** GET FILE GROUP
***************************************************************************** */
void	ft_get_file_group(char *filename, struct stat stbuf)
{
	struct group	*gr;

	ft_putstr("Group: ");
	gr = getgrgid(stbuf.st_gid);
	ft_putstr(gr->gr_name);
	ft_putchar('\n');
}

/* *****************************************************************************
** GET FILE SIZE
***************************************************************************** */
void ft_get_file_size(char *filename, struct stat stbuf)
{
	ft_putstr("Size: ");
	ft_putnbr(stbuf.st_size);
	ft_putendl("B");
}

/* *****************************************************************************
** GET FILE MODIFICATION DATE
***************************************************************************** */
void ft_get_file_date(char *filename, struct stat stbuf)
{
	ft_putstr("Last Modification Date: ");
	ft_putnbr(stbuf.st_mtime);
	ft_putendl("");
}

/* *****************************************************************************
** INSPECT FILE FUNCTION
***************************************************************************** */
int		ft_inspect_file(char *filename)
{
	struct stat		stbuf;

	if (stat(filename, &stbuf))
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
	ft_get_file_abs_path(filename, stbuf);
	ft_get_file_name(filename);
	ft_get_file_type(filename, stbuf);
	ft_get_file_perms(filename, stbuf);
	ft_get_file_links(filename, stbuf);
	ft_get_file_owner(filename, stbuf);
	ft_get_file_group(filename, stbuf);
	ft_get_file_size(filename, stbuf);
	ft_get_file_date(filename, stbuf);
	return (0);
}

/* *****************************************************************************
** MAIN
***************************************************************************** */
int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("usage: ./ft_inspect_file <file or folder name>");
	else
		ft_inspect_file(av[1]);
	return (0);
}
