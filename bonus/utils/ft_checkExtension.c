/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkExtension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:16:53 by bben-aou          #+#    #+#             */
/*   Updated: 2022/11/10 15:08:03 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int ft_check_extension(char *str)
{
   int	len;

	len = ft_strlen1(str);
	if (str[len - 4] == '.')
		if (str[len - 3] == 'c')
			if (str[len - 2] == 'u')
				if (str[len - 1] == 'b')
					return (1);
	return (0);
}