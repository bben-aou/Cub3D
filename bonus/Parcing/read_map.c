/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:21:41 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/15 19:29:28 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static char	*get_next_line_b(int fd, t_varb *var)
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
	var->buff = ft_strdup_bonus_b(str);
	return (var->buff);
}

void	initialize_datab(t_varb *var)
{
	var->map = NULL;
	var->buff = NULL;
	var->count_line = 0;
	var->save = NULL;
}

int	check_mapb_startb(char *str, t_varb *var)
{
	int	i;

	i = 0;
	if (!str)
		ft_msg_errorb("\033[91mThere is no map in the file !\033[91m", var);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1' || str[i] == '0')
			return (1);
		else if (str[i] != '1' && str[i] != '0' && str[i] != ' ' \
			&& str[i] != '\n')
			ft_msg_errorb("Invalid Map !", var);
		else
		{
			free(str);
			return (0);
		}
	}
	return (0);
}

void	read_mapb(t_varb *var)
{
	int		i;
	char	*line_to_join;

	i = 0;
	line_to_join = get_next_line1(var->fd);
	while ((check_mapb_startb(line_to_join, var) == 0) && line_to_join != NULL)
		line_to_join = get_next_line1(var->fd);
	if (!line_to_join)
		ft_msg_errorb("Invalid Map !", var);
	initialize_datab(var);
	var->save = get_next_line_b(var->fd, var);
	var->map_in_line = ft_strjoin1(line_to_join, var->save);
	var->map = ft_split_bonus_b(var->map_in_line, '\n');
	free(var->map_in_line);
	free(var->save);
	i = 0;
	if (var->map == NULL)
		error_map_b("Occured during Split of Data!!!", var);
	while (var->map[i])
		i++;
	var->count_line = i;
	check_mapb(var);
	printf("\033[1;32mMap is Clear\033[0;m\n");
}
