/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:21:41 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/09 17:04:22 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char *get_next_lineB(int fd, t_var *var)
{
	char str[1000000];
	char buff[1];
	int i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, 1) == 1)
	{
		str[i] = buff[0];
		i++;
	}
	str[i] = '\0';
	var->buff = ft_strdupB(str);
	return (var->buff);
}

void	initialize_data(t_var *var)
{
	var->map = NULL;
	var->buff = NULL;
	var->count_line = 0;
	var->save = NULL;
}

int	checkMapSrat(char *str)
{
	int i;

	i = 0;
	if (!str)
		ft_messageError("\033[91mThere is no map in the file !\033[91m");
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1' || str[i] == '0')
			return (1);
		else if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '\n')
			ft_messageError("Invalid Map !");
		else
			return (0);
	}
	return (0);
}
void	read_map(t_var *var)
{
	int	i;
	char *lineToJoin;

	i = 0;
	lineToJoin = get_next_line(var->fd);
	while ((checkMapSrat(lineToJoin) == 0) && lineToJoin != NULL)
		lineToJoin = get_next_line(var->fd);
	if (!lineToJoin)
		ft_messageError("Invalid Map !");
	initialize_data(var);
	var->save = get_next_lineB(var->fd, var);
	var->mapInLine = ft_strjoin(lineToJoin, var->save);
	var->map = ft_splitB(var->mapInLine, '\n');
	i = 0;
	if (var->map == NULL)
		error_mapB("Occured during Split of Data!!!", var);
	while (var->map[i])
		i++;
	var->count_line = i;
	check_map(var);
	printf("\033[1;32mMap is Clear\033[0;m\n");
}