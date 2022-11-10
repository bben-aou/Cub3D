/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:52:24 by iomayr            #+#    #+#             */
/*   Updated: 2022/11/09 17:10:43 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


char	*ft_strdupB(char *str)
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

int	ft_strcmpB(char *str, char *ptr)
{
	int	i;

	i = 0;
	while (str[i] && ptr[i] && str[i] == ptr[i])
		i++;
	return (str[i] - ptr[i]);
}

void	error_mapB(char *msg, t_var *var)
{
	var->nothing = 0;
    printf("Oups Error : %s\n", msg);
    exit(1);
}