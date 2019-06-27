/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gngobeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 07:59:15 by gngobeni          #+#    #+#             */
/*   Updated: 2019/06/27 13:39:26 by gngobeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		fill_line(char **s, const int fd)
{
	char 	*str;
	char 	*temps;
	size_t	len;
	
	*s = NULL;
	while (get_next_line(fd, &str))
	{
		if (!*s)
			*s = ft_strdup(str);
		else
		{
			len = ft_strlen(*s); 
			temps = ft_strnew(ft_strlen(*s) + 1);
			ft_strcpy(temps, *s);
			temps[len] = '\n';
			ft_strdel(s);
			*s = ft_strjoin(temps, str);
			ft_strdel(&temps);
			ft_strdel(&str);
		}
	}
}

#include <stdio.h>

int			main(int argc, char **argv)
{
	int 	fd[argc - 1];
	char	*s[argc - 1];

	if (argc > 1)
	{
		for (int i = 0, ii = 1; ii < argc; i++, ii++)
			fd[i] = open(argv[ii], O_RDONLY);

		for (int i = 0; i < (argc - 1); i++)
			fill_line(&s[i], fd[i]);
		for (int i = 0; i < (argc - 1); i++)
		{
			ft_putstr("-----------------------------------------------------");
			ft_putendl(argv[i + 1]);
			ft_putendl(s[i]);
		}
	}
	sleep(60);	
	return (0);
}
