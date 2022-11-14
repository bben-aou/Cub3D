/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:21:41 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 14:12:13 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*get_next_line_b(int fd, t_var *var)
{
	char	str[1000000];
	char	buff[1];
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, 1) == 1)
	{
		str[i] = buff[0];
		i++;
	}
	str[i] = '\0';
	var->buff = ft_strdup_b(str);
	return (var->buff);
}

void	initialize_data(t_var *var)
{
	var->map = NULL;
	var->buff = NULL;
	var->count_line = 0;
	var->save = NULL;
}

int	check_map_start(char *str)
{
	int	i;

	i = 0;
	if (!str)
		ft_msg_error("\033[91mThere is no map in the file !\033[91m");
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1' || str[i] == '0')
			return (1);
		else if (str[i] != '1' && str[i] != '0' && str[i] != ' ' \
			&& str[i] != '\n')
			ft_msg_error("Invalid Map !");
		else
			return (0);
	}
	return (0);
}

void	read_map(t_var *var)
{
	int		i;
	char	*line_to_join;

	i = 0;
	line_to_join = get_next_line(var->fd);
	while ((check_map_start(line_to_join) == 0) && line_to_join != NULL)
		line_to_join = get_next_line(var->fd);
	if (!line_to_join)
		ft_msg_error("Invalid Map !");
	initialize_data(var);
	var->save = get_next_line_b(var->fd, var);
	var->mapInLine = ft_strjoin(line_to_join, var->save);
	var->map = ft_split_b(var->mapInLine, '\n');
	free(var->save);
	i = 0;
	if (var->map == NULL)
		error_map("Occured during Split of Data!!!", var);
	while (var->map[i])
		i++;
	var->count_line = i;
	check_map(var);
	printf("\033[1;32mMap is Clear\033[0;m\n");
}
