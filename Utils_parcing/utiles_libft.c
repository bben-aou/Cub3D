/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:52:24 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/14 16:49:55 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup_b(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * ft_strlen1(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = (char)str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strcmp_b(char *str, char *ptr)
{
	int	i;

	i = 0;
	while (str[i] && ptr[i] && str[i] == ptr[i])
		i++;
	return (str[i] - ptr[i]);
}

void	error_map(char *msg, t_var *var)
{
	var->nothing = 0;
	printf("Oups Error : %s\n", msg);
	exit(1);
}
